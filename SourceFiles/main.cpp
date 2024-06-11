#include "../headerFiles/mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "../headerFiles/WeaterData.h"

QString CITY_NAME = "Gliwice";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1000, 667);

    WeatherData& weather_data = WeatherData::getInstance();

    QObject::connect(&weather_data, &WeatherData::dataReady, [&weather_data]() {
        qDebug() << QString::fromStdString(std::to_string(weather_data.getTemp()));
    });

    weather_data.setCity(CITY_NAME);

    w.show();
    return a.exec();
}
