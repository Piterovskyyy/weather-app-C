#ifndef FIREBASE_H
#define FIREBASE_H

#include <QNetworkRequest>
#include <QString>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>
#include <QObject>
#include <vector>
#include "WeaterData.h"
#include <algorithm>
#include <cctype>

class Firebase : public QObject {
    Q_OBJECT
public:
    Firebase() {}

    static Firebase& getInstance() {
        static Firebase instance;
        return instance;
    }

    std::vector<std::string> favCities;

    void fetchCities() {
        QUrl url(FIREBASE_URL);
        QNetworkRequest request(url);

        QNetworkReply* reply = manager.get(request);

        connect(reply, &QNetworkReply::finished, this, [this, reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray responseData = reply->readAll();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
                QJsonObject jsonObj = jsonDoc.object();

                favCities.clear(); // Clear current list before updating
                for(int i = 0; i < 5; i++) {
                    if (jsonObj.contains("favCities") && jsonObj["favCities"].isArray() && i < jsonObj["favCities"].toArray().size()) {
                        favCities.push_back(jsonObj["favCities"][i].toString().toStdString());
                    } else {
                        favCities.push_back(""); // Ensure size is always 5
                    }
                }

                emit dataReady();
            } else {
                qDebug() << "Blad pobierania danych z API!" << reply->errorString();
            }

            reply->deleteLater();
        });
    }

    void toggleFavorite() {
        std::string city = weather_data.getCity();

        // Convert city to lowercase
        std::transform(city.begin(), city.end(), city.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        auto it = std::find_if(favCities.begin(), favCities.end(),
                               [&city](const std::string& favCity) {
                                   std::string lowerFavCity = favCity;
                                   std::transform(lowerFavCity.begin(), lowerFavCity.end(), lowerFavCity.begin(),
                                                  [](unsigned char c){ return std::tolower(c); });
                                   return lowerFavCity == city;
                               });

        if (it != favCities.end()) {
            // City is already in favorites, remove it
            favCities.erase(it);
        } else {
            // City is not in favorites, add it to the nearest free spot
            bool added = false;
            for (size_t i = 0; i < favCities.size(); ++i) {
                if (favCities[i].empty()) {
                    favCities[i] = weather_data.getCity(); // add city without transforming again
                    added = true;
                    break;
                }
            }

            if (!added && favCities.size() < 5) {
                favCities.push_back(weather_data.getCity()); // add city without transforming again
            } else if (!added) {
                qDebug() << "Lista ulubionych miast jest pełna!";
                // Optionally, you can notify the user here
            }
            //tutaj chyba
        }

        emit listReady();
    }

signals:
    void dataReady();
    void listReady();

private:
    QNetworkAccessManager manager;
    QString FIREBASE_URL = "https://pk-aplikacja-pogodowa-default-rtdb.europe-west1.firebasedatabase.app/.json";
    WeatherData& weather_data = WeatherData::getInstance();
};

#endif // FIREBASE_H
