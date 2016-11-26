#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <creation.h>
#include <makewm.h>
#include <validation.h>

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

private:
    Ui::menu *ui;
};

#endif // MENU_H
