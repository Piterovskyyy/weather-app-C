#include "../headerFiles/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

const QString API_KEY = "9b3f921e313f6cdbdc4125aaff8759d1";
const QString CITY_NAME = "Gliwice";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1000,667);
    w.show();

    // Tworzymy menedżera dostępu do sieci
    QNetworkAccessManager manager;

    // Tworzymy żądanie do wykonania
    QUrl url("https://api.openweathermap.org/data/2.5/weather");
    QUrlQuery query;
    query.addQueryItem("q", CITY_NAME);
    query.addQueryItem("units", "metric");
    query.addQueryItem("appid", API_KEY);
    url.setQuery(query);

    QNetworkRequest request(url);

    // Wykonujemy żądanie i otrzymujemy odpowiedź
    QNetworkReply *reply = manager.get(request);

    // Obsługujemy odpowiedź
    QObject::connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Odczytujemy odpowiedź
            QByteArray responseData = reply->readAll();

            // Parsujemy JSON
            QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
            QJsonObject jsonObj = jsonDoc.object();

            // Wyciągamy interesujące nas informacje
            QString weatherDescription = jsonObj["weather"].toArray()[0].toObject()["description"].toString();
            double temperature = jsonObj["main"].toObject()["temp"].toDouble();
            double feelsLike = jsonObj["main"].toObject()["feels_like"].toDouble();
            int humidity = jsonObj["main"].toObject()["humidity"].toInt();

            qDebug() << "Opis pogody:" << weatherDescription;
            qDebug() << "Temperatura:" << temperature << "°C";
            qDebug() << "Temperatura odczuwalna:" << feelsLike << "°C";
            qDebug() << "Wilgotność:" << humidity << "%";
            // Obsługujemy błąd odpowiedzi
            qDebug() << "Błąd:" << reply->errorString();
        }

        // Usuwamy obiekt odpowiedzi
        reply->deleteLater();
    });

    return a.exec();
}
