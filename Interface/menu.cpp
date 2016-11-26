#include "menu.h"
#include "ui_menu.h"
#include "creation.h"
#include "makewm.h"
#include "validation.h"
#include <QPixmap>

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile(":/resources/img/menu.png");
    setWindowTitle("Main menu");
    setWindowIcon(icon);
    QPixmap pix1(":/resources/img/create.png");
    int w1 = ui->img1->width();
    int h1 = ui->img1->height();
    ui->img1->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    QPixmap pix2(":/resources/img/validate.png");
    int w2 = ui->img2->width();
    int h2 = ui->img2->height();
    ui->img2->setPixmap(pix2.scaled(w2,h2,Qt::KeepAspectRatio));
}

menu::~menu()
{
    delete ui;
}

void menu::on_createButton_clicked()
{
    creation cW;
    cW.setModal(true);
    cW.exec();
}

void menu::on_validateButton_clicked()
{
    validation vW;
    vW.setModal(true);
    vW.exec();
}
