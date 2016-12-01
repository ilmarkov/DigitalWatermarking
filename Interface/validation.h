#ifndef VALIDATION_H
#define VALIDATION_H

#include <QDialog>
#include "menu.h"

namespace Ui {
class validation;
}

class validation : public QDialog
{
    Q_OBJECT

public:

    explicit validation(QWidget *parent = 0);
    ~validation();

    void set_controller(QTController* c){
        controller = c;
    }

private slots:
    void on_browseImage_2_clicked();

    void on_browseMark_2_clicked();

    void on_ok_clicked();

    void on_cancel_clicked();



private:
    Ui::validation *ui;
    QTController* controller;

};

#endif // VALIDATION_H
