#include "../headerFiles/search.h"
#include "../headerFiles/Ui/searchUi.h"
#include <QDebug>

Search::Search(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Search)
{
    ui->setupUi(this);
    connect(ui->searchButton, &QPushButton::clicked, this, &Search::setCity);
    WeatherData& weather_data = WeatherData::getInstance();
    connect(&weather_data, &WeatherData::dataReady, this, &Search::updateUI);
}

Search::~Search()
{
    delete ui;
}

void Search::setCity()
{
    QString cityName = ui->textInput->text();
    WeatherData& weather_data = WeatherData::getInstance();
    weather_data.setCity(cityName);
    qDebug() << "Szukane miasto: " << cityName;
}

void Search::updateUI()
{
    WeatherData& weather_data = WeatherData::getInstance();
    // Przykład aktualizacji UI:
    qDebug() << "Dane pogody dla: " << QString::fromStdString(weather_data.getCity());
    qDebug() << "Temperatura: " << weather_data.getTemp();
    // Tutaj dodaj kod do aktualizacji interfejsu użytkownika danymi pogodowymi
}
