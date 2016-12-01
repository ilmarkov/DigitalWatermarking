#ifndef MAKEWM_H
#define MAKEWM_H

#include <QDialog>
#include "menu.h"

namespace Ui {
class makeWM;
}

class makeWM : public QDialog
{
    Q_OBJECT


public:
    explicit makeWM(QWidget *parent = 0);
    ~makeWM();

    void set_controller(QTController* c){
        controller = c;
    }

private slots:
    void on_browseKey_clicked();

    void on_ok_clicked();

    void on_cancel_clicked();

    void on_browseNewMark_clicked();

private:
    Ui::makeWM *ui;
    QTController* controller;


};

#endif // MAKEWM_H
