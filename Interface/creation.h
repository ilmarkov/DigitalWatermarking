#ifndef CREATION_H
#define CREATION_H

#include <QDialog>
#include <menu.h>
#include <makewm.h>
#include <validation.h>

namespace Ui {
class creation;
}

class creation : public QDialog
{
    Q_OBJECT

Controller controller;	
	
public:
    explicit creation(QWidget *parent = 0);
    ~creation();

private slots:
    void on_createWM_clicked();

    void on_browseImage_clicked();

    void on_browseMark_clicked();

    void on_browseNewImage_clicked();

    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::creation *ui;
};

#endif // CREATION_H
