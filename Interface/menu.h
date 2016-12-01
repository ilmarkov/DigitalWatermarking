#ifndef MENU_H
#define MENU_H



#include <QWidget>
class QTController;

#include "creation.h"
#include "validation.h"
#include "../Controllers/QTController.h"

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = 0);
    ~menu();

public slots:

    void on_createButton_clicked();

    void on_validateButton_clicked();

    void set_controller(QTController* c){
        controller = c;
    }

private:
    Ui::menu *ui;
    QTController* controller;
};

#endif // MENU_H
