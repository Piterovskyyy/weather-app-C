#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <iostream>
#include <string>
#include <vector>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>

class WeatherData : public QObject {
    Q_OBJECT
public:
    explicit WeatherData(const QString& apiKey, QObject* parent = nullptr) : QObject(parent), API_KEY(apiKey) {}

    void setCity(const QString& cityName) {
        fetchCity(cityName);
    }

    std::string getMain() const { return response_data.main; }
    std::string getDescription() const { return response_data.description; }
    std::string getIcon() const { return response_data.icon; }
    int getTemp() const { return response_data.temp; }
    int getFeelsLike() const { return response_data.feels_like; }
    int getTempMin() const { return response_data.temp_min; }
    int getTempMax() const { return response_data.temp_max; }
    int getPressure() const { return response_data.pressure; }
    int getHumidity() const { return response_data.humidity; }
    int getVisibility() const { return response_data.visibility; }
    int getWind() const { return response_data.wind; }
    int getClouds() const { return response_data.clouds; }

signals:
    void dataReady();

private:
    QString API_KEY;
    QString API_URL = "https://api.openweathermap.org/data/2.5/weather";
    QNetworkAccessManager manager;

    struct ResponseData {
        std::string main;
        std::string description;
        std::string icon;
        int temp;
        int feels_like;
        int temp_min;
        int temp_max;
        int pressure;
        int humidity;
        int visibility;
        int wind;
        int clouds;
    };

    ResponseData response_data;

    void fetchCity(const QString& cityName) {
        QUrl url(API_URL);
        QUrlQuery query;
        query.addQueryItem("q", cityName);
        query.addQueryItem("units", "metric");
        query.addQueryItem("appid", API_KEY);
        url.setQuery(query);
        QNetworkRequest request(url);

        QNetworkReply* reply = manager.get(request);

        connect(reply, &QNetworkReply::finished, this, [this, reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray responseData = reply->readAll();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
                QJsonObject jsonObj = jsonDoc.object();

                response_data.main = jsonObj["weather"].toArray()[0].toObject()["main"].toString().toStdString();
                response_data.description = jsonObj["weather"].toArray()[0].toObject()["description"].toString().toStdString();
                response_data.icon = jsonObj["weather"].toArray()[0].toObject()["icon"].toString().toStdString();
                response_data.temp = jsonObj["main"].toObject()["temp"].toInt();
                response_data.feels_like = jsonObj["main"].toObject()["feels_like"].toInt();
                response_data.temp_min = jsonObj["main"].toObject()["temp_min"].toInt();
                response_data.temp_max = jsonObj["main"].toObject()["temp_max"].toInt();
                response_data.pressure = jsonObj["main"].toObject()["pressure"].toInt();
                response_data.humidity = jsonObj["main"].toObject()["humidity"].toInt();
                response_data.visibility = jsonObj["visibility"].toInt();
                response_data.wind = jsonObj["wind"].toObject()["speed"].toInt();
                response_data.clouds = jsonObj["clouds"].toObject()["all"].toInt();

                emit dataReady();
            }

            reply->deleteLater();
        });
    }
};

#endif // WEATHERDATA_H
