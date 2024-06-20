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

    // Metoda statyczna do uzyskiwania instancji singletona klasy
    static Firebase& getInstance() {
        static Firebase instance;
        return instance;
    }

    std::vector<std::string> favCities;

    // Metoda odpowiedzialna za synchronizację aktualnego stanu wektora favCities z bazą danych
    void updateDatabase() {
        QUrl url(FIREBASE_URL);
        QNetworkRequest request(url);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QJsonArray jsonArray;
        // Przekształcanie wektora favCities na QJsonArray
        for (const std::string& city : favCities) {
            jsonArray.append(QString::fromStdString(city));
        }

        QJsonObject jsonObject;
        jsonObject["favCities"] = jsonArray;
        QJsonDocument jsonDoc(jsonObject);
        QByteArray jsonData = jsonDoc.toJson();

        QNetworkReply* reply = manager.put(request, jsonData);

        // Obsługa zakończenia żądania HTTP
        connect(reply, &QNetworkReply::finished, this, [this, reply]() {
            if (reply->error() != QNetworkReply::NoError) {
                qDebug() << "Błąd aktualizacji danych w bazie:" << reply->errorString();
            }
            reply->deleteLater();
        });
    }

    // Metoda odpowiedzialna za pobieranie miast z bazy danych
    void fetchCities() {
        QUrl url(FIREBASE_URL);
        QNetworkRequest request(url);

        // Wykonanie zapytania do Firebase
        QNetworkReply* reply = manager.get(request);

        connect(reply, &QNetworkReply::finished, this, [this, reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray responseData = reply->readAll();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
                QJsonObject jsonObj = jsonDoc.object();

                favCities.clear(); // Czyszczenie listy ulubionych miast
                for(int i = 0; i < 5; i++) {
                    if (jsonObj.contains("favCities") && jsonObj["favCities"].isArray() && i < jsonObj["favCities"].toArray().size()) {
                        favCities.push_back(jsonObj["favCities"][i].toString().toStdString());
                    } else {
                        favCities.push_back("");
                    }
                }

                emit dataReady();
            } else {
                qDebug() << "Błąd pobierania danych z API!" << reply->errorString();
            }

            reply->deleteLater();
        });
    }

    // Metoda odpowiedzialna za dodawanie lub usuwanie miasta z listy ulubionych
    void toggleFavorite() {
        std::string city = weather_data.getCity();

        // Zmiana na małe litery
        std::transform(city.begin(), city.end(), city.begin(),
                       [](unsigned char c){ return std::tolower(c); });

        // Szukanie miasta w liście ulubionych miast
        auto it = std::find_if(favCities.begin(), favCities.end(),
                               [&city](const std::string& favCity) {
                                   std::string lowerFavCity = favCity;
                                   std::transform(lowerFavCity.begin(), lowerFavCity.end(), lowerFavCity.begin(),
                                                  [](unsigned char c){ return std::tolower(c); });
                                   return lowerFavCity == city;
                               });

        if (it != favCities.end()) {
            // Jeżeli miasto jest już w ulubionych, usuń je
            favCities.erase(it);
        } else {
            // Dodanie do wolnego miejsca
            bool added = false;
            for (size_t i = 0; i < favCities.size(); ++i) {
                if (favCities[i].empty()) {
                    favCities[i] = weather_data.getCity();
                    added = true;
                    break;
                }
            }

            if (!added && favCities.size() < 5) {
                favCities.push_back(weather_data.getCity()); // Dodaj miasto, jeśli lista nie jest pełna
            } else if (!added) {
                qDebug() << "Lista ulubionych miast jest pełna!";
            }
        }

        updateDatabase();

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
