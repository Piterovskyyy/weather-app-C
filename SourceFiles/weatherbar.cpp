#include "../headerFiles/weatherbar.h"
#include "../headerFiles/Ui/weatherbarUi.h"

WeatherBar::WeatherBar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WeatherBar)
{
    ui->setupUi(this);
}

WeatherBar::~WeatherBar()
{
    delete ui;
}
