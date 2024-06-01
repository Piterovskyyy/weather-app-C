/********************************************************************************
** Form generated from reading UI file 'list.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LISTUI_H
#define LISTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_List
{
public:
    QLabel *header;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QLabel *background;
    QPushButton *star;

    void setupUi(QWidget *List)
    {
        if (List->objectName().isEmpty())
            List->setObjectName("List");
        List->resize(290, 270);
        List->setStyleSheet(QString::fromUtf8("QLabel#background{\n"
"	background-color: rgba(121, 122, 122, 228);\n"
"	border-radius: 20px;\n"
"	\n"
"}\n"
"QPushButton:hover{\n"
"color: rgb(66, 67, 67)\n"
"}\n"
"QPushButton{\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"font-size: 16px;\n"
"color: white;\n"
"}\n"
"QPushButton#star{\n"
"	image: url(../images/icons/star.svg);\n"
"}\n"
""));
        header = new QLabel(List);
        header->setObjectName("header");
        header->setGeometry(QRect(0, 7, 291, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(14);
        font.setUnderline(false);
        header->setFont(font);
        header->setStyleSheet(QString::fromUtf8("color: white;\n"));
        header->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(List);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 30, 291, 232));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        pushButton->setFont(font1);

        verticalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");

        verticalLayout->addWidget(pushButton_4);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");

        verticalLayout->addWidget(pushButton_6);

        background = new QLabel(List);
        background->setObjectName("background");
        background->setGeometry(QRect(0, 0, 290, 270));
        star = new QPushButton(List);
        star->setObjectName("star");
        star->setGeometry(QRect(20, 7, 71, 27));
        star->setStyleSheet(QString::fromUtf8(""));
        background->raise();
        header->raise();
        verticalLayoutWidget->raise();
        star->raise();




        retranslateUi(List);

        QMetaObject::connectSlotsByName(List);
    } // setupUi

    void retranslateUi(QWidget *List)
    {
        List->setWindowTitle(QCoreApplication::translate("List", "Form", nullptr));
        header->setText(QCoreApplication::translate("List", "Ulubione miasta", nullptr));
        pushButton->setText(QCoreApplication::translate("List", "Krak\303\263w", nullptr));
        pushButton_3->setText(QCoreApplication::translate("List", "Warszawa", nullptr));
        pushButton_4->setText(QCoreApplication::translate("List", "Gda\305\204sk", nullptr));
        pushButton_2->setText(QCoreApplication::translate("List", "Gliwice", nullptr));
        pushButton_6->setText(QCoreApplication::translate("List", "Pozna\305\204", nullptr));
        background->setText(QString());
        star->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class List: public Ui_List {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LISTUI_H
