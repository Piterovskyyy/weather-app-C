#ifndef WEATHERBAR_H
#define WEATHERBAR_H

#include <QWidget>

namespace Ui {
class WeatherBar;
}

class WeatherBar : public QWidget
{
    Q_OBJECT

public:
    explicit WeatherBar(QWidget *parent = nullptr);
    ~WeatherBar();

private:
    Ui::WeatherBar *ui;
};

#endif // WEATHERBAR_H
