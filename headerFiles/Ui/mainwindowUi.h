/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef MAINWINDOWUI_H
#define MAINWINDOWUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

#include "../WeaterData.h"
#include "../../headerFiles/date.h"
#include "../../headerFiles/list.h"
#include "../../headerFiles/search.h"
#include "../../headerFiles/weatherbar.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    // WeatherData weather_data;
    QWidget *centralwidget;
    Search *widget;
    QLabel *lcdNumber;
    Date *widget_2;
    WeatherBar *widget_3;
    List *widget_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 667);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setAutoFillBackground(false);
        centralwidget->setStyleSheet(QString::fromUtf8("QWidget#centralwidget{\n"
"	\n"
"	\n"
"	background-image: url(../images/backgrounds/rain.png);\n"
"background-repeat: no-repeat;\n"
"}"));
        widget = new Search(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 0, 301, 61));
        widget->setStyleSheet(QString::fromUtf8("*{\n"
"background-color: rgb(255, 255, 255);\n"
"}"));
        lcdNumber = new QLabel(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(380, 200, 191, 111));
        widget_2 = new Date(centralwidget);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(580, 0, 420, 80));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: white;"));
        widget_3 = new WeatherBar(centralwidget);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 367, 1000, 300));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget_4 = new List(centralwidget);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(10, 70, 290, 270));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgba(74, 75, 75, 218);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lcdNumber->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINWINDOWUI_H
