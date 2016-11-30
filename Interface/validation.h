#ifndef VALIDATION_H
#define VALIDATION_H

#include <QDialog>
#include <creation.h>
#include <makewm.h>
#include <menu.h>

namespace Ui {
class validation;
}

class validation : public QDialog
{
    Q_OBJECT

public:
    explicit validation(QWidget *parent = 0);
    ~validation();

private slots:
    void on_browseImage_2_clicked();

    void on_browseMark_2_clicked();

    void on_ok_clicked();

    void on_cancel_clicked();

private:
    Ui::validation *ui;
};

#endif // VALIDATION_H
