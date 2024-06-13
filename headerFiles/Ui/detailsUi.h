/********************************************************************************
** Form generated from reading UI file 'details.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DETAILSUI_H
#define DETAILSUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

#include "../WeaterData.h"

QT_BEGIN_NAMESPACE

class Ui_Details {
public:
    QLabel *visibility;
    QLabel *cloud;
    QLabel *feelsLike;
    QLabel *preasure;
    QLabel *visibilityIcon;
    QLabel *cloudIcon;
    QLabel *preasureIcon;
    QLabel *feelLikeIcon;
    QLabel *wind;
    QLabel *rain;
    QLabel *windIcon;
    QLabel *rainIcon;
    QLabel *maxTemp;
    QLabel *minTemp;
    QLabel *feelLikeIcon_2;
    QLabel *feelLikeIcon_3;
    WeatherData &weather_data = WeatherData::getInstance();

    void setupUi(QWidget *Details) {
        if (Details->objectName().isEmpty())
            Details->setObjectName("Details");
        Details->resize(667, 300);
        Details->setStyleSheet(QString::fromUtf8("QLabel\n"
            "{\n"
            "	\n"
            "	background-color: rgba(121, 122, 122, 230);\n"
            "       width: 300px;\n"
            "       border: 0px solid white;\n"
            "       border-radius: 15px;\n"
            "       padding-left: 42px;\n"
            "       color: white;\n"
            "       font-size: 17px;\n"
            "}\n"
            ""));
        visibility = new QLabel(Details);
        visibility->setObjectName("visibility");
        visibility->setGeometry(QRect(340, 220, 311, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        visibility->setFont(font);
        visibility->setFrameShape(QFrame::StyledPanel);
        visibility->setFrameShadow(QFrame::Plain);
        visibility->setMidLineWidth(3);
        cloud = new QLabel(Details);
        cloud->setObjectName("cloud");
        cloud->setGeometry(QRect(340, 150, 311, 60));
        cloud->setFont(font);
        cloud->setFrameShape(QFrame::StyledPanel);
        cloud->setFrameShadow(QFrame::Plain);
        cloud->setMidLineWidth(3);
        feelsLike = new QLabel(Details);
        feelsLike->setObjectName("feelsLike");
        feelsLike->setGeometry(QRect(0, 10, 311, 60));
        feelsLike->setFont(font);
        feelsLike->setStyleSheet(QString::fromUtf8(""));
        feelsLike->setFrameShape(QFrame::StyledPanel);
        feelsLike->setFrameShadow(QFrame::Plain);
        feelsLike->setMidLineWidth(3);
        preasure = new QLabel(Details);
        preasure->setObjectName("preasure");
        preasure->setGeometry(QRect(0, 220, 311, 60));
        preasure->setFont(font);
        preasure->setFrameShape(QFrame::StyledPanel);
        preasure->setFrameShadow(QFrame::Plain);
        preasure->setMidLineWidth(3);
        visibilityIcon = new QLabel(Details);
        visibilityIcon->setObjectName("visibilityIcon");
        visibilityIcon->setGeometry(QRect(308, 235, 71, 31));
        visibilityIcon->setStyleSheet(QString::fromUtf8("border: 0px;\n"
            "image: url(../images/icons/eye.svg);\n"
            "background-color: rgba(255, 255, 255, 0);"));
        cloudIcon = new QLabel(Details);
        cloudIcon->setObjectName("cloudIcon");
        cloudIcon->setGeometry(QRect(308, 165, 71, 31));
        cloudIcon->setStyleSheet(QString::fromUtf8("border: 0px;\n"
            "image: url(../images/icons/cloud.svg);\n"
            "background-color: rgba(255, 255, 255, 0);"));
        preasureIcon = new QLabel(Details);
        preasureIcon->setObjectName("preasureIcon");
        preasureIcon->setGeometry(QRect(-32, 235, 71, 31));
        preasureIcon->setStyleSheet(QString::fromUtf8("border: 0px;\n"
            "image: url(../images/icons/preasure.png);\n"
            "background-color: rgba(255, 255, 255, 0);"));
        feelLikeIcon = new QLabel(Details);
        feelLikeIcon->setObjectName("feelLikeIcon");
        feelLikeIcon->setGeometry(QRect(-28, 25, 71, 31));
        feelLikeIcon->setStyleSheet(QString::fromUtf8("border: 0px;\n"
            "image: url(../images/icons/temp.png);\n"
            "background-color: rgba(255, 255, 255, 0);"));
        wind = new QLabel(Details);
        wind->setObjectName("wind");
        wind->setGeometry(QRect(340, 10, 311, 60));
        wind->setFont(font);
        wind->setStyleSheet(QString::fromUtf8(""));
        wind->setFrameShape(QFrame::StyledPanel);
        wind->setFrameShadow(QFrame::Plain);
        wind->setMidLineWidth(3);
        rain = new QLabel(Details);
        rain->setObjectName("rain");
        rain->setGeometry(QRect(340, 80, 311, 60));
        rain->setFont(font);
        rain->setStyleSheet(QString::fromUtf8(""));
        rain->setFrameShape(QFrame::StyledPanel);
        rain->setFrameShadow(QFrame::Plain);
        rain->setMidLineWidth(3);
        windIcon = new QLabel(Details);
        windIcon->setObjectName("windIcon");
        windIcon->setGeometry(QRect(308, 25, 71, 31));
        windIcon->setStyleSheet(QString::fromUtf8("border: 0px;\n"
            "image: url(../images/icons/wind.svg);\n"
            "background-color: rgba(255, 255, 255, 0);"));
        rainIcon = new QLabel(Details);
        rainIcon->setObjectName("rainIcon");
        rainIcon->setGeometry(QRect(308, 95, 71, 31));
        rainIcon->setStyleSheet(QString::fromUtf8("border: 0px;\n"
            "image: url(../images/icons/humidity.png);\n"
            "background-color: rgba(255, 255, 255, 0);"));
        maxTemp = new QLabel(Details);
        maxTemp->setObjectName("maxTemp");
        maxTemp->setGeometry(QRect(0, 150, 311, 60));
        maxTemp->setFont(font);
        maxTemp->setStyleSheet(QString::fromUtf8(""));
        maxTemp->setFrameShape(QFrame::StyledPanel);
        maxTemp->setFrameShadow(QFrame::Plain);
        maxTemp->setMidLineWidth(3);
        minTemp = new QLabel(Details);
        minTemp->setObjectName("minTemp");
        minTemp->setGeometry(QRect(0, 80, 311, 60));
        minTemp->setFont(font);
        minTemp->setStyleSheet(QString::fromUtf8(""));
        minTemp->setFrameShape(QFrame::StyledPanel);
        minTemp->setFrameShadow(QFrame::Plain);
        minTemp->setMidLineWidth(3);
        feelLikeIcon_2 = new QLabel(Details);
        feelLikeIcon_2->setObjectName("feelLikeIcon_2");
        feelLikeIcon_2->setGeometry(QRect(-28, 95, 71, 31));
        feelLikeIcon_2->setStyleSheet(QString::fromUtf8("border: 0px;\n"
            "image: url(../images/icons/tempmin.png);\n"
            "background-color: rgba(255, 255, 255, 0);"));
        feelLikeIcon_3 = new QLabel(Details);
        feelLikeIcon_3->setObjectName("feelLikeIcon_3");
        feelLikeIcon_3->setGeometry(QRect(-28, 165, 71, 31));
        feelLikeIcon_3->setStyleSheet(QString::fromUtf8("border: 0px;\n"
            "image: url(../images/icons/tempmax.png);\n"
            "background-color: rgba(255, 255, 255, 0);"));
        visibility->raise();
        cloud->raise();
        feelsLike->raise();
        preasure->raise();
        preasureIcon->raise();
        feelLikeIcon->raise();
        wind->raise();
        rain->raise();
        windIcon->raise();
        rainIcon->raise();
        maxTemp->raise();
        minTemp->raise();
        cloudIcon->raise();
        visibilityIcon->raise();
        feelLikeIcon_2->raise();
        feelLikeIcon_3->raise();

        retranslateUi(Details);

        QMetaObject::connectSlotsByName(Details);
    } // setupUi

    void retranslateUi(QWidget *Details) {
        QObject::connect(&weather_data, &WeatherData::dataReady, Details, [this]() {
            updateUI();
        });

        Details->setWindowTitle(QCoreApplication::translate("Details", "Form", nullptr));
        // visibility->setText(QCoreApplication::translate("Details", "Widoczno\305\233\304\207: 23 km", nullptr));
        // cloud->setText(QCoreApplication::translate("Details", "Zachmurzenie: 75 %", nullptr));
        // feelsLike->setText(QCoreApplication::translate("Details", "Temperatura odczuwalna: 26\302\260C", nullptr));
        // preasure->setText(QCoreApplication::translate("Details", "Ci\305\233nienie: 1001 hPa", nullptr));
        visibilityIcon->setText(QString());
        cloudIcon->setText(QString());
        preasureIcon->setText(QString());
        feelLikeIcon->setText(QString());
        // wind->setText(QCoreApplication::translate("Details", "Wiatr: bezwietrznie", nullptr));
        // rain->setText(QCoreApplication::translate("Details", "Opady: 30 %", nullptr));
        windIcon->setText(QString());
        rainIcon->setText(QString());
        // maxTemp->setText(QCoreApplication::translate("Details", "Max. temperatura: 27\302\260C", nullptr));
        // minTemp->setText(QCoreApplication::translate("Details", "Min. temperatura: 23\302\260C", nullptr));
        feelLikeIcon_2->setText(QString());
        feelLikeIcon_3->setText(QString());
    } // retranslateUi

    void updateUI() {
        std::string visString = ( "Widoczno\305\233\304\207: " + QString::number(weather_data.getVisibility(), 'f', 0) + " km").toStdString();
        visibility->setText(QCoreApplication::translate("Details", visString.c_str(), nullptr));

        std::string cloudString = ( "Zachmurzenie: " + QString::number(weather_data.getClouds(), 'f', 0) + " %").toStdString();
        cloud->setText(QCoreApplication::translate("Details", cloudString.c_str(), nullptr));

        std::string feelsString = ( "Temperatura odczuwalna: " + QString::number(weather_data.getFeelsLike(), 'f', 0) + "\302\260C").toStdString();
        feelsLike->setText(QCoreApplication::translate("Details", feelsString.c_str(), nullptr));

        std::string preasureString = ( "Ci\305\233nienie: " + QString::number(weather_data.getPressure(), 'f', 0) + " hPa").toStdString();
        preasure->setText(QCoreApplication::translate("Details", preasureString.c_str(), nullptr));

        std::string windString = ( "Wiatr: " + QString::number(weather_data.getWind(), 'f', 0) + " m/s").toStdString();
        wind->setText(QCoreApplication::translate("Details", windString.c_str(), nullptr));

        std::string humidityString = ( "Wilgotność: " + QString::number(weather_data.getHumidity(), 'f', 0) + " %").toStdString();
        rain->setText(QCoreApplication::translate("Details", humidityString.c_str(), nullptr));

        std::string maxTempString = ( "Max. temperatura: " + QString::number(weather_data.getTempMax(), 'f', 0) + "\302\260C").toStdString();
        maxTemp->setText(QCoreApplication::translate("Details", maxTempString.c_str(), nullptr));

        std::string minTempString = ( "Min. temperatura: " + QString::number(weather_data.getTempMin(), 'f', 0) + "\302\260C").toStdString();
        minTemp->setText(QCoreApplication::translate("Details", minTempString.c_str(), nullptr));
    }
};

namespace Ui {
    class Details : public Ui_Details {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // DETAILSUI_H
