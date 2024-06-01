#ifndef DATE_H
#define DATE_H

#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QMainWindow>
#include <QMovie>
#include <QDateTime>
#include<QTimeZone>


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
};

#endif // DATE_H
