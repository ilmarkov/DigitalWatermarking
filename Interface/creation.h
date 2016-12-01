#ifndef CREATION_H
#define CREATION_H


#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include "menu.h"
#include "makewm.h"

namespace Ui {
class creation;
}

class creation : public QDialog
{
    Q_OBJECT


public:
    explicit creation(QWidget *parent = 0);
    ~creation();

    void set_controller(QTController* c){
        controller = c;
    }

private slots:
    void on_createWM_clicked();

    void on_browseImage_clicked();

    void on_browseMark_clicked();

    void on_browseNewImage_clicked();

    void on_ok_clicked();

    void on_cancel_clicked();



private:
    Ui::creation *ui;
    QTController* controller;
};

#endif // CREATION_H
