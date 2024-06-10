/********************************************************************************
** Form generated from reading UI file 'date.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DATEUI_H
#define DATEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Date
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *timeLabel;
    QLabel *label_gif_animation;

    void setupUi(QWidget *Date)
    {
        if (Date->objectName().isEmpty())
            Date->setObjectName("Date");
        Date->resize(120, 80);
        Date->setStyleSheet(QString::fromUtf8("QWidget#Date{\n"
"background-color: transparent;\n"
"}\n"
"QLabel#timeLabel{\n"
"color: white;\n"
"}"));
        verticalLayoutWidget = new QWidget(Date);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-10, 49, 401, 31));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(25);
        label->setFont(font);


        verticalLayout->addWidget(label, 0, Qt::AlignRight);

        timeLabel = new QLabel(Date);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(160, 10, 441, 35));
        timeLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 25px;"));
        timeLabel->setFont(font);
        label_gif_animation = new QLabel(Date);
        label_gif_animation->setObjectName("label_gif_animation");
        label_gif_animation->setGeometry(QRect(125, 11, 31, 35));
        QFont font1;
        font1.setPointSize(10);
        label_gif_animation->setFont(font1);
        label_gif_animation->setStyleSheet(QString::fromUtf8("image: url(../images/icons/clock.svg);"));
        label_gif_animation->setScaledContents(false);


        retranslateUi(Date);

        QMetaObject::connectSlotsByName(Date);
    } // setupUi

    void retranslateUi(QWidget *Date)
    {
        Date->setWindowTitle(QCoreApplication::translate("Date", "Form", nullptr));
        label->setText(QCoreApplication::translate("Date", "Gliwice, Polska", nullptr));
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"font-size: 25px;"));
        timeLabel->setText(QString());
        label_gif_animation->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Date: public Ui_Date {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DATEUI_H
