/********************************************************************************
** Form generated from reading UI file 'creation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATION_H
#define UI_CREATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_creation
{
public:
    QGroupBox *chooseImg;
    QToolButton *browseImage;
    QLineEdit *pathImage;
    QGroupBox *chooseMark;
    QLineEdit *pathMark;
    QToolButton *browseMark;
    QPushButton *createWM;
    QGroupBox *saveImg;
    QToolButton *browseNewImage;
    QLineEdit *pathNewImage;
    QPushButton *cancel;
    QPushButton *ok;

    void setupUi(QDialog *creation)
    {
        if (creation->objectName().isEmpty())
            creation->setObjectName(QStringLiteral("creation"));
        creation->setEnabled(true);
        creation->resize(371, 257);
        chooseImg = new QGroupBox(creation);
        chooseImg->setObjectName(QStringLiteral("chooseImg"));
        chooseImg->setGeometry(QRect(10, 10, 351, 51));
        browseImage = new QToolButton(chooseImg);
        browseImage->setObjectName(QStringLiteral("browseImage"));
        browseImage->setGeometry(QRect(280, 20, 61, 21));
        pathImage = new QLineEdit(chooseImg);
        pathImage->setObjectName(QStringLiteral("pathImage"));
        pathImage->setEnabled(true);
        pathImage->setGeometry(QRect(10, 20, 261, 20));
        pathImage->setReadOnly(true);
        chooseMark = new QGroupBox(creation);
        chooseMark->setObjectName(QStringLiteral("chooseMark"));
        chooseMark->setGeometry(QRect(10, 70, 351, 81));
        pathMark = new QLineEdit(chooseMark);
        pathMark->setObjectName(QStringLiteral("pathMark"));
        pathMark->setEnabled(true);
        pathMark->setGeometry(QRect(10, 20, 261, 20));
        pathMark->setReadOnly(true);
        browseMark = new QToolButton(chooseMark);
        browseMark->setObjectName(QStringLiteral("browseMark"));
        browseMark->setGeometry(QRect(280, 20, 61, 21));
        createWM = new QPushButton(chooseMark);
        createWM->setObjectName(QStringLiteral("createWM"));
        createWM->setGeometry(QRect(10, 50, 171, 23));
        saveImg = new QGroupBox(creation);
        saveImg->setObjectName(QStringLiteral("saveImg"));
        saveImg->setGeometry(QRect(10, 160, 351, 51));
        browseNewImage = new QToolButton(saveImg);
        browseNewImage->setObjectName(QStringLiteral("browseNewImage"));
        browseNewImage->setGeometry(QRect(280, 20, 61, 21));
        pathNewImage = new QLineEdit(saveImg);
        pathNewImage->setObjectName(QStringLiteral("pathNewImage"));
        pathNewImage->setEnabled(true);
        pathNewImage->setGeometry(QRect(10, 20, 261, 20));
        pathNewImage->setReadOnly(true);
        cancel = new QPushButton(creation);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(280, 220, 75, 23));
        ok = new QPushButton(creation);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(190, 220, 75, 23));

        retranslateUi(creation);

        QMetaObject::connectSlotsByName(creation);
    } // setupUi

    void retranslateUi(QDialog *creation)
    {
        creation->setWindowTitle(QApplication::translate("creation", "Dialog", 0));
        chooseImg->setTitle(QApplication::translate("creation", "Choose image", 0));
        browseImage->setText(QApplication::translate("creation", "Browse", 0));
        chooseMark->setTitle(QApplication::translate("creation", "Choose watermark file", 0));
        browseMark->setText(QApplication::translate("creation", "Browse", 0));
        createWM->setText(QApplication::translate("creation", "Create new watermark file", 0));
        saveImg->setTitle(QApplication::translate("creation", "Save image with watermark to", 0));
        browseNewImage->setText(QApplication::translate("creation", "Browse", 0));
        cancel->setText(QApplication::translate("creation", "Cancel", 0));
        ok->setText(QApplication::translate("creation", "OK", 0));
    } // retranslateUi

};

namespace Ui {
    class creation: public Ui_creation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATION_H
