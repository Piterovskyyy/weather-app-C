#include "../headerFiles/date.h"
#include "../headerFiles/Ui/dateUi.h"

Date::Date(QWidget *parent) : QWidget(parent),
                              ui(new Ui::Date),
                              timer(new QTimer(this)) {
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &Date::updateClock);
    timer->start(1000);
    updateClock(); // Pierwsza aktualizacja zegara

    QObject::connect(&weather_data, &WeatherData::dataReady, this, [this]() {
        QTimeZone timeZone(weather_data.getTimezone());
        QDateTime currentTimeInZone = QDateTime::currentDateTime().toTimeZone(timeZone);
        QString formattedTime = currentTimeInZone.toString("yyyy-MM-dd HH:mm:ss");
        ui->timeLabel->setText(formattedTime);
        QString city = QString::fromStdString(weather_data.getCity());
        if (!city.isEmpty()) {
            city[0] = city[0].toUpper();
        }
        ui->label->setText(city);

    });
}

Date::~Date() {
    delete ui;
}

void Date::updateClock() {
    QTimeZone timeZone(weather_data.getTimezone());
    QDateTime currentTimeInZone = QDateTime::currentDateTime().toTimeZone(timeZone);
    QString formattedTime = currentTimeInZone.toString("yyyy-MM-dd HH:mm:ss");
    ui->timeLabel->setText(formattedTime);
}
