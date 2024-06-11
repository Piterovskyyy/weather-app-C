#include "../headerFiles/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "../headerFiles/WeaterData.h"

const QString API_KEY = "";
QString CITY_NAME = "Gliwice";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1000, 667);
    w.show();

    WeatherData weather_data(API_KEY);

    QObject::connect(&weather_data, &WeatherData::dataReady, [&weather_data]() {
        qDebug() << QString::fromStdString(weather_data.getDescription());
    });

    weather_data.setCity(CITY_NAME); // Pobrane dane po otrzymaniu odpowiedzi z API

    return a.exec();
}
