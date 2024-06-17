#include "../headerFiles/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "../headerFiles/WeaterData.h"
#include <iostream>

#include "../headerFiles/firebase.h"

QString CITY_NAME = "Gliwice";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1000, 667);

    WeatherData& weather_data = WeatherData::getInstance();
    // Firebase& firebase = Firebase::getInstance();

    // QObject::connect(&weather_data, &WeatherData::dataReady, [&weather_data]() {
    //     qDebug() << QString::fromStdString(std::to_string(weather_data.getTimezone()));
    // });
    // firebase.fetchCities();

    // QObject::connect(&firebase, &Firebase::dataReady, [&firebase]() {
    //     // firebase.fetchCities();
    //         qDebug() << firebase.favCities[0];
    //     qDebug() << firebase.favCities[1];
    //
    //     qDebug() << firebase.favCities[3];
    // });

    // firebase.fetchCities();



    weather_data.setCity(CITY_NAME);

    w.show();
    return a.exec();
}
