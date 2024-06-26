#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
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

    // Metoda do uzyskiwania instancji singletona klasy
    static WeatherData& getInstance() {
        static WeatherData instance;
        return instance;
    }

    // Metoda odpowiedzialna za aktualizację aktualnie wybranego miasta
    void setCity(const QString& cityName) {
        city = cityName.toStdString();

        // Wywołanie metody prywatnej rozpoczynającej aktualizację stanu instancji
        fetchCity(cityName);
    }

    // Gettery & settery
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
    int getTimezone() const { return response_data.timezone; }
    double getWindDir() const { return response_data.windDir; }
    std::string getCity() const { return city; }

    // Sygnał informujący o gotowych danych
signals:
    void dataReady();

private:
    static const QString API_KEY;
    QString API_URL = "https://api.openweathermap.org/data/2.5/weather";
    QNetworkAccessManager manager;

    std::string city;

    // Struktura do przechowywania danych z API
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
        double timezone;
        double windDir;
    };

    ResponseData response_data;

    // Konstruktor prywatny zgodnie z wzorcem singletona
    WeatherData(QObject* parent = nullptr) : QObject(parent) {}

    // Prywatny konstruktor kopiujący (niezaimplementowany) zgodnie z wzorcem singletona
    WeatherData(const WeatherData&) = delete;
    WeatherData& operator=(const WeatherData&) = delete;

    // Metoda odpowiedzialna za pobieranie danych o pogodzie z API
    void fetchCity(const QString& cityName) {
        QUrl url(API_URL);
        QUrlQuery query;

        // Dodanie potrzebnych do zapytania HTTPS argumentów
        query.addQueryItem("lang", "pl"); // Sprecyzowanie języka
        query.addQueryItem("q", cityName); // Nazwa wybranego miasta
        query.addQueryItem("units", "metric"); // Jednostki
        query.addQueryItem("appid", API_KEY);
        url.setQuery(query);
        QNetworkRequest request(url);

        // Żądanie do API
        QNetworkReply* reply = manager.get(request);

        // Obsługa zakończenia żądania HTTP
        connect(reply, &QNetworkReply::finished, this, [this, reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray responseData = reply->readAll();
                QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
                QJsonObject jsonObj = jsonDoc.object();

                // Przekazanie danych do struktury reprezentującej nasze dane
                response_data.main = jsonObj["weather"].toArray()[0].toObject()["main"].toString().toStdString();
                response_data.description = jsonObj["weather"].toArray()[0].toObject()["description"].toString().toStdString();
                response_data.icon = jsonObj["weather"].toArray()[0].toObject()["icon"].toString().toStdString();
                response_data.temp = std::round(jsonObj["main"].toObject()["temp"].toDouble());
                response_data.windDir = jsonObj["wind"].toObject()["deg"].toDouble();
                response_data.feels_like = jsonObj["main"].toObject()["feels_like"].toDouble();
                response_data.temp_min = jsonObj["main"].toObject()["temp_min"].toDouble();
                response_data.temp_max = jsonObj["main"].toObject()["temp_max"].toDouble();
                response_data.pressure = jsonObj["main"].toObject()["pressure"].toDouble();
                response_data.humidity = jsonObj["main"].toObject()["humidity"].toDouble();
                response_data.visibility = jsonObj["visibility"].toDouble();
                response_data.wind = jsonObj["wind"].toObject()["speed"].toDouble();
                response_data.clouds = jsonObj["clouds"].toObject()["all"].toDouble();
                response_data.timezone = jsonDoc.object()["timezone"].toInt();

                emit dataReady();
            } else {
                qDebug() << "Błąd pobierania danych z API!";
            }

            reply->deleteLater();
        });
    }
};

#endif // WEATHERDATA_H
