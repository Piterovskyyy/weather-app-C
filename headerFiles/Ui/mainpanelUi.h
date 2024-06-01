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

QT_BEGIN_NAMESPACE

class Ui_MainPanel
{
public:
    QLabel *icon;
    QLabel *description;
    QLabel *label;
    QPushButton *star;

    void setupUi(QWidget *MainPanel)
    {
        if (MainPanel->objectName().isEmpty())
            MainPanel->setObjectName("MainPanel");
        MainPanel->resize(333, 300);
        MainPanel->setStyleSheet(QString::fromUtf8("QWidget#MainPanel{\n"
"background-color: transparent;\n"
"}\n"
"QLabel#icon{\n"
"	image: url(../images/icons/w3.png);\n"
"}\n"
"QLabel#description{\n"
"text-align: center;\n"
"}\n"
"QPushButton#star{\n"
"background-color: transparent;\n"
"	image: url(../images/icons/star.svg);\n"
"}\n"
"QPushButton#star:hover{\n"
"background-color: transparent;\n"
"	image: url(../images/icons/star2.svg);\n"
"}\n"
""));
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

    void retranslateUi(QWidget *MainPanel)
    {
        MainPanel->setWindowTitle(QCoreApplication::translate("MainPanel", "Form", nullptr));
        icon->setText(QString());
        description->setText(QCoreApplication::translate("MainPanel", "cloudy", nullptr));
        label->setText(QCoreApplication::translate("MainPanel", "28\302\260C", nullptr));
        star->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainPanel: public Ui_MainPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // MAINPANELUI_H