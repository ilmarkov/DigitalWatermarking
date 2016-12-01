/********************************************************************************
** Form generated from reading UI file 'validation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VALIDATION_H
#define UI_VALIDATION_H

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

class Ui_validation
{
public:
    QGroupBox *chooseMark;
    QLineEdit *pathMark_2;
    QToolButton *browseMark_2;
    QGroupBox *chooseImg;
    QToolButton *browseImage_2;
    QLineEdit *pathImage_2;
    QPushButton *ok;
    QPushButton *cancel;

    void setupUi(QDialog *validation)
    {
        if (validation->objectName().isEmpty())
            validation->setObjectName(QStringLiteral("validation"));
        validation->resize(372, 164);
        chooseMark = new QGroupBox(validation);
        chooseMark->setObjectName(QStringLiteral("chooseMark"));
        chooseMark->setGeometry(QRect(10, 70, 351, 51));
        pathMark_2 = new QLineEdit(chooseMark);
        pathMark_2->setObjectName(QStringLiteral("pathMark_2"));
        pathMark_2->setEnabled(true);
        pathMark_2->setGeometry(QRect(10, 20, 261, 20));
        pathMark_2->setReadOnly(true);
        browseMark_2 = new QToolButton(chooseMark);
        browseMark_2->setObjectName(QStringLiteral("browseMark_2"));
        browseMark_2->setGeometry(QRect(280, 20, 61, 21));
        chooseImg = new QGroupBox(validation);
        chooseImg->setObjectName(QStringLiteral("chooseImg"));
        chooseImg->setGeometry(QRect(10, 10, 351, 51));
        browseImage_2 = new QToolButton(chooseImg);
        browseImage_2->setObjectName(QStringLiteral("browseImage_2"));
        browseImage_2->setGeometry(QRect(280, 20, 61, 21));
        pathImage_2 = new QLineEdit(chooseImg);
        pathImage_2->setObjectName(QStringLiteral("pathImage_2"));
        pathImage_2->setEnabled(true);
        pathImage_2->setGeometry(QRect(10, 20, 261, 20));
        pathImage_2->setReadOnly(true);
        ok = new QPushButton(validation);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(190, 130, 75, 23));
        cancel = new QPushButton(validation);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(280, 130, 75, 23));

        retranslateUi(validation);

        QMetaObject::connectSlotsByName(validation);
    } // setupUi

    void retranslateUi(QDialog *validation)
    {
        validation->setWindowTitle(QApplication::translate("validation", "Dialog", 0));
        chooseMark->setTitle(QApplication::translate("validation", "Choose authentic watermark", 0));
        browseMark_2->setText(QApplication::translate("validation", "Browse", 0));
        chooseImg->setTitle(QApplication::translate("validation", "Choose image to validate", 0));
        browseImage_2->setText(QApplication::translate("validation", "Browse", 0));
        ok->setText(QApplication::translate("validation", "OK", 0));
        cancel->setText(QApplication::translate("validation", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class validation: public Ui_validation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VALIDATION_H
