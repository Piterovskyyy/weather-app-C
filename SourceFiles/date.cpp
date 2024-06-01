#include "../headerFiles/date.h"
#include "../headerFiles/Ui/dateUi.h"


Date::Date(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Date),
    timer(new QTimer(this))
{
    ui->setupUi(this);

    connect(timer, &QTimer::timeout, this, &Date::updateClock);
    timer->start(1000);
    updateClock(); // Pierwsza aktualizacja zegara
}

Date::~Date()
{
    delete ui;
}

void Date::updateClock()

{
    QTimeZone timeZone(-14400);
    QDateTime currentTimeInZone = QDateTime::currentDateTime().toTimeZone(timeZone);
    QString formattedTime = currentTimeInZone.toString("yyyy-MM-dd HH:mm:ss");
    ui->timeLabel->setText(formattedTime);
}
