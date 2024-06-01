/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SEARCHUI_H
#define SEARCHUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QPushButton *searchButton;
    QLineEdit *textInput;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName("Search");
        Search->resize(257, 61);
        Search->setStyleSheet(QString::fromUtf8("*{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton#searchButton:hover{\n"
"	image: url(../images/icons/szara.png);\n"
"background-color: transparent;\n"
"width: 40px;\n"
"height: 30px;\n"
"}\n"
"QPushButton#searchButton{\n"
"	image: url(../images/icons/lupka.png);\n"
"background-color: transparent;\n"
"width: 40px;\n"
"height: 30px;\n"
"}\n"
"QLineEdit#textInput{\n"
"background-color: transparent;\n"
"width: 40px;\n"
"height: 30px;\n"
"border-bottom: 1px solid white;\n"
"outline: none;\n"
"padding-top: 15px;\n"
"padding-left: 5px;\n"
"color: white;\n"
"}"));
        searchButton = new QPushButton(Search);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(210, 20, 31, 31));
        searchButton->setMinimumSize(QSize(0, 25));
        searchButton->setStyleSheet(QString::fromUtf8(""));
        searchButton->setIconSize(QSize(32, 32));
        textInput = new QLineEdit(Search);
        textInput->setObjectName("textInput");
        textInput->setEnabled(true);
        textInput->setGeometry(QRect(10, 10, 201, 40));
        textInput->setMinimumSize(QSize(0, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(13);
        font.setKerning(false);
        textInput->setFont(font);
        textInput->setFrame(false);
        textInput->setClearButtonEnabled(false);

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Form", nullptr));
        searchButton->setText(QString());
        textInput->setPlaceholderText(QCoreApplication::translate("Search", "Wyszukaj miasto...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SEARCHUI_H
