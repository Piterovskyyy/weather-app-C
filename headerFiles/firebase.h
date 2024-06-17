//
// Created by janek on 17.06.2024.
//

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

                // Wypisz response
                qDebug() << "Response data:" << jsonObj["favCities"][0].toString().toStdString();

                for(int i = 0; i < 5; i++) {
                    favCities.push_back(jsonObj["favCities"][i].toString().toStdString());
                }

                // QString citiesString = jsonObj["favCities"].toString();
                // QStringList citiesList = citiesString.split(',');
                //
                // // Konwersja QStringList na std::vector<QString>
                // favCities.clear();
                // for (const QString& city : citiesList) {
                //     favCities.push_back(city.trimmed());
                // }
                //
                // for (const auto& city : favCities) {
                //     qDebug() << "City:" << city;
                // }

                emit dataReady();
            } else {
                qDebug() << "Blad pobierania danych z API!" << reply->errorString();
            }

            reply->deleteLater();
        });
    }

signals:
    void dataReady();

private:
    QNetworkAccessManager manager;
    QString FIREBASE_URL = "https://pk-aplikacja-pogodowa-default-rtdb.europe-west1.firebasedatabase.app/.json";
};

#endif //FIREBASE_H
