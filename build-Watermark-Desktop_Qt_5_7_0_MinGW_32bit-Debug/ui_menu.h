/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QLabel *mainLabel;
    QPushButton *createButton;
    QPushButton *validateButton;
    QLabel *img1;
    QLabel *img2;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(262, 184);
        mainLabel = new QLabel(menu);
        mainLabel->setObjectName(QStringLiteral("mainLabel"));
        mainLabel->setGeometry(QRect(90, 10, 91, 16));
        createButton = new QPushButton(menu);
        createButton->setObjectName(QStringLiteral("createButton"));
        createButton->setGeometry(QRect(20, 140, 91, 31));
        validateButton = new QPushButton(menu);
        validateButton->setObjectName(QStringLiteral("validateButton"));
        validateButton->setGeometry(QRect(150, 140, 91, 31));
        img1 = new QLabel(menu);
        img1->setObjectName(QStringLiteral("img1"));
        img1->setGeometry(QRect(20, 40, 91, 91));
        img2 = new QLabel(menu);
        img2->setObjectName(QStringLiteral("img2"));
        img2->setGeometry(QRect(150, 40, 91, 91));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "menu", 0));
        mainLabel->setText(QApplication::translate("menu", "Digital Watermark", 0));
        createButton->setText(QApplication::translate("menu", "Create", 0));
        validateButton->setText(QApplication::translate("menu", "Validate", 0));
        img1->setText(QString());
        img2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
