#ifndef DATE_H
#define DATE_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>
#include <QTimeZone>
#include "../headerFiles/WeaterData.h"

namespace Ui {
    class Date;
}

class Date : public QWidget
{
    Q_OBJECT

public:
    explicit Date(QWidget *parent = nullptr);
    ~Date();

    private slots:
        void updateClock();

private:
    Ui::Date *ui;
    QTimer *timer;
    WeatherData& weather_data = WeatherData::getInstance();
};

#endif // DATE_H
