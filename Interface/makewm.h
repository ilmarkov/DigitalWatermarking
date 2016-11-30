#ifndef MAKEWM_H
#define MAKEWM_H

#include <QDialog>
#include <creation.h>
#include <menu.h>
#include <validation.h>

namespace Ui {
class makeWM;
}

class makeWM : public QDialog
{
    Q_OBJECT

public:
    explicit makeWM(QWidget *parent = 0);
    ~makeWM();

private slots:
    void on_browseKey_clicked();

    void on_ok_clicked();

    void on_cancel_clicked();

    void on_browseNewMark_clicked();

private:
    Ui::makeWM *ui;
};

#endif // MAKEWM_H
