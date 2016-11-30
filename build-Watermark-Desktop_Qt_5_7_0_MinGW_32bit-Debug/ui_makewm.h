/********************************************************************************
** Form generated from reading UI file 'makewm.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKEWM_H
#define UI_MAKEWM_H

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

class Ui_makeWM
{
public:
    QGroupBox *enterKey;
    QLineEdit *editKey;
    QGroupBox *chooseKey;
    QLineEdit *pathKey;
    QToolButton *browseKey;
    QPushButton *cancel;
    QPushButton *ok;
    QGroupBox *saveMark;
    QToolButton *browseNewMark;
    QLineEdit *pathNewMark;

    void setupUi(QDialog *makeWM)
    {
        if (makeWM->objectName().isEmpty())
            makeWM->setObjectName(QStringLiteral("makeWM"));
        makeWM->resize(371, 224);
        enterKey = new QGroupBox(makeWM);
        enterKey->setObjectName(QStringLiteral("enterKey"));
        enterKey->setGeometry(QRect(10, 10, 351, 51));
        editKey = new QLineEdit(enterKey);
        editKey->setObjectName(QStringLiteral("editKey"));
        editKey->setGeometry(QRect(10, 20, 331, 20));
        editKey->setEchoMode(QLineEdit::Password);
        chooseKey = new QGroupBox(makeWM);
        chooseKey->setObjectName(QStringLiteral("chooseKey"));
        chooseKey->setGeometry(QRect(10, 70, 351, 51));
        pathKey = new QLineEdit(chooseKey);
        pathKey->setObjectName(QStringLiteral("pathKey"));
        pathKey->setEnabled(true);
        pathKey->setGeometry(QRect(10, 20, 261, 20));
        pathKey->setEchoMode(QLineEdit::Normal);
        pathKey->setReadOnly(true);
        browseKey = new QToolButton(chooseKey);
        browseKey->setObjectName(QStringLiteral("browseKey"));
        browseKey->setGeometry(QRect(280, 20, 61, 20));
        cancel = new QPushButton(makeWM);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(280, 190, 75, 23));
        ok = new QPushButton(makeWM);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setGeometry(QRect(190, 190, 75, 23));
        saveMark = new QGroupBox(makeWM);
        saveMark->setObjectName(QStringLiteral("saveMark"));
        saveMark->setGeometry(QRect(10, 130, 351, 51));
        browseNewMark = new QToolButton(saveMark);
        browseNewMark->setObjectName(QStringLiteral("browseNewMark"));
        browseNewMark->setGeometry(QRect(280, 20, 61, 21));
        pathNewMark = new QLineEdit(saveMark);
        pathNewMark->setObjectName(QStringLiteral("pathNewMark"));
        pathNewMark->setEnabled(true);
        pathNewMark->setGeometry(QRect(10, 20, 261, 20));
        pathNewMark->setReadOnly(true);

        retranslateUi(makeWM);
        QObject::connect(editKey, SIGNAL(textEdited(QString)), pathKey, SLOT(clear()));
        QObject::connect(pathKey, SIGNAL(textChanged(QString)), editKey, SLOT(clear()));

        QMetaObject::connectSlotsByName(makeWM);
    } // setupUi

    void retranslateUi(QDialog *makeWM)
    {
        makeWM->setWindowTitle(QApplication::translate("makeWM", "Dialog", 0));
        enterKey->setTitle(QApplication::translate("makeWM", "Enter key phrase...", 0));
        chooseKey->setTitle(QApplication::translate("makeWM", "...or import key phrase from *.txt file", 0));
        browseKey->setText(QApplication::translate("makeWM", "Browse", 0));
        cancel->setText(QApplication::translate("makeWM", "Cancel", 0));
        ok->setText(QApplication::translate("makeWM", "OK", 0));
        saveMark->setTitle(QApplication::translate("makeWM", "Save new watermark to", 0));
        browseNewMark->setText(QApplication::translate("makeWM", "Browse", 0));
    } // retranslateUi

};

namespace Ui {
    class makeWM: public Ui_makeWM {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKEWM_H
