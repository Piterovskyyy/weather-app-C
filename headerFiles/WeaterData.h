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
    static WeatherData& getInstance() {
        static WeatherData instance;
        return instance;
    }

    void setCity(const QString& cityName) {
        fetchCity(cityName);
    }

    std::string getMain() const { return response_data.main; }
    std::string getDescription() const { return response_data.description; }
    std::string getIcon() const { return response_data.icon; }
    double getTemp() const { return response_data.temp; }
    double getFeelsLike() const { return response_data.feels_like; }
    double getTempMin() const { return response_data.temp_min; }
    double getTempMax() const { return response_data.temp_max; }
    double getPressure() const { return response_data.pressure; }
    double getHumidity() const { return response_data.humidity; }
    double getVisibility() const { return response_data.visibility; }
    double getWind() const { return response_data.wind; }
    double getClouds() const { return response_data.clouds; }

signals:
    void dataReady();

private:
    static const QString API_KEY;
    QString API_URL = "https://api.openweathermap.org/data/2.5/weather";
    QNetworkAccessManager manager;

    struct ResponseData {
        std::string main;
        std::string description;
        std::string icon;
        double temp;
        double feels_like;
        double temp_min;
        double temp_max;
        double pressure;
        double humidity;
        double visibility;
        double wind;
        double clouds;
    };

    ResponseData response_data;

    WeatherData(QObject* parent = nullptr) : QObject(parent) {}

    WeatherData(const WeatherData&) = delete;
    WeatherData& operator=(const WeatherData&) = delete;

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
                response_data.temp = floor(jsonObj["main"].toObject()["temp"].toDouble());

                response_data.feels_like = jsonObj["main"].toObject()["feels_like"].toDouble();
                response_data.temp_min = jsonObj["main"].toObject()["temp_min"].toDouble();
                response_data.temp_max = jsonObj["main"].toObject()["temp_max"].toDouble();
                response_data.pressure = jsonObj["main"].toObject()["pressure"].toDouble();
                response_data.humidity = jsonObj["main"].toObject()["humidity"].toDouble();
                response_data.visibility = jsonObj["visibility"].toDouble();
                response_data.wind = jsonObj["wind"].toObject()["speed"].toDouble();
                response_data.clouds = jsonObj["clouds"].toObject()["all"].toDouble();

                emit dataReady();
            }

            reply->deleteLater();
        });
    }
};

#endif // WEATHERDATA_H
