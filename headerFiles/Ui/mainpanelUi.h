/********************************************************************************
** Form generated from reading UI file 'mainpanel.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINPANELUI_H
#define MAINPANELUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "../WeaterData.h"
#include "../firebase.h"
#include <algorithm>
#include <cctype>

QT_BEGIN_NAMESPACE

class Ui_MainPanel {
public:
    QLabel *icon;
    QLabel *description;
    QLabel *label;
    QPushButton *star;

    // Instancje (singleton) WeatherData i Firebase
    WeatherData &weather_data = WeatherData::getInstance();
    Firebase &firebase = Firebase::getInstance();

    void setupUi(QWidget *MainPanel) {
        if (MainPanel->objectName().isEmpty())
            MainPanel->setObjectName("MainPanel");
        MainPanel->resize(333, 300);
        MainPanel->setStyleSheet(QString::fromUtf8("QWidget#MainPanel{\n"
            "background-color: transparent;\n"
            "}\n"
            "QLabel#description{\n"
            "text-align: center;\n"
            "}\n"
        ));
        icon = new QLabel(MainPanel);
        icon->setObjectName("icon");
        icon->setGeometry(QRect(30, 50, 150, 150));
        icon->setScaledContents(false);
        description = new QLabel(MainPanel);
        description->setObjectName("description");
        description->setGeometry(QRect(0, 160, 333, 32));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(18);
        description->setFont(font);
        description->setStyleSheet(QString::fromUtf8("color: white;\n"));
        description->setAlignment(Qt::AlignCenter);
        label = new QLabel(MainPanel);
        label->setObjectName("label");
        label->setGeometry(QRect(120, 90, 183, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(32);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet(QString::fromUtf8("color: white;\n"));
        star = new QPushButton(MainPanel);
        star->setObjectName("star");
        star->setGeometry(QRect(5, 15, 51, 31));

        retranslateUi(MainPanel);

        QMetaObject::connectSlotsByName(MainPanel);
    } // setupUi

    void retranslateUi(QWidget *MainPanel) {

        // Aktualizacja UI (wywołanie odpowiednich funkcji) po uzyskaniu danych z API/bazy danych
        QObject::connect(&weather_data, &WeatherData::dataReady, MainPanel, [this]() {
            updateUI();
        });
        QObject::connect(star, &QPushButton::clicked, MainPanel, [this]() {
            firebase.toggleFavorite();
            updateStarIcon();
        });
        MainPanel->setWindowTitle(QCoreApplication::translate("MainPanel", "Form", nullptr));
        icon->setText(QString());
        star->setText(QString());
    } // retranslateUi

    // Aktualizacja UI w oparciu o dane z API/bazy danych
    void updateUI() {
        description->setText(QCoreApplication::translate("MainPanel", weather_data.getDescription().c_str(), nullptr));
        std::string iconUrl = "QLabel#icon{\n"
                              "	image: url(../images/icons/" + weather_data.getIcon() + ".png);\n"
                              "}\n";
        icon->setStyleSheet(QString::fromUtf8(iconUrl));
        std::string tempString = (QString::number(weather_data.getTemp(), 'f', 0) + "\302\260C").toStdString();
        label->setText(QCoreApplication::translate("MainPanel", tempString.c_str(), nullptr));
        updateStarIcon();
    }

    // Obsługa gwiazdki "dodaj do ulubionych"
    void updateStarIcon() {
        bool isFav;
        for (const auto &city : firebase.favCities) {
            std::string lowerCity = city;
            std::transform(lowerCity.begin(), lowerCity.end(), lowerCity.begin(),
                           [](unsigned char c){ return std::tolower(c); });

            std::string currentCity = weather_data.getCity();
            std::transform(currentCity.begin(), currentCity.end(), currentCity.begin(),
                           [](unsigned char c){ return std::tolower(c); });

            if (lowerCity == currentCity) {
                isFav = true;
                break;
            }
        }

        if (!isFav) {
            star->setStyleSheet(QString::fromUtf8("QPushButton#star{\n"
                "background-color: transparent;\n"
                "	image: url(../images/icons/star.svg);\n"
                "}\n"
                "QPushButton#star:hover{\n"
                "background-color: transparent;\n"
                "	image: url(../images/icons/star2.svg);\n"
                "}\n"
            ));
        } else {
            star->setStyleSheet(QString::fromUtf8("QPushButton#star{\n"
                "background-color: transparent;\n"
                "	image: url(../images/icons/star3.svg);\n"
                "}\n"
                "QPushButton#star:hover{\n"
                "background-color: transparent;\n"
                "	image: url(../images/icons/star.svg);\n"
                "}\n"
            ));
        }
    }


};

namespace Ui {
    class MainPanel : public Ui_MainPanel {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINPANELUI_H
