/********************************************************************************
** Form generated from reading UI file 'weatherbar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef WEATHERBARUI_H
#define WEATHERBARUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>
#include "../../headerFiles/details.h"
#include "../../headerFiles/mainpanel.h"

QT_BEGIN_NAMESPACE

class Ui_WeatherBar
{
public:
    QLabel *back;
    MainPanel *widget;
    Details *widget_2;

    void setupUi(QWidget *WeatherBar)
    {
        if (WeatherBar->objectName().isEmpty())
            WeatherBar->setObjectName("WeatherBar");
        WeatherBar->resize(1000, 300);
        WeatherBar->setStyleSheet(QString::fromUtf8("QWidget#WeatherBar{\n"
"background-color: transparent;\n"
"}\n"
"QLabel#back{\n"
"	background-color: rgba(121, 122, 122, 150);\n"
"border-top: 1px solid white;\n"
"}"));
        back = new QLabel(WeatherBar);
        back->setObjectName("back");
        back->setGeometry(QRect(0, 0, 1000, 400));
        widget = new MainPanel(WeatherBar);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 333, 300));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        widget_2 = new Details(WeatherBar);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(333, 0, 667, 300));

        retranslateUi(WeatherBar);

        QMetaObject::connectSlotsByName(WeatherBar);
    } // setupUi

    void retranslateUi(QWidget *WeatherBar)
    {
        WeatherBar->setWindowTitle(QCoreApplication::translate("WeatherBar", "Form", nullptr));
        back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WeatherBar: public Ui_WeatherBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // WEATHERBARUI_H
