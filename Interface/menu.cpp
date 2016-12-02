#include "ui_menu.h"
#include "menu.h"

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile("../Interface/img/menu.png");
    setWindowTitle("Main menu");
    setWindowIcon(icon);
    QPixmap pix1("../Interface/img/create.png");
    int w1 = ui->img1->width();
    int h1 = ui->img1->height();
    ui->img1->setPixmap(pix1.scaled(w1,h1,Qt::KeepAspectRatio));
    QPixmap pix2("../Interface/img/validate.png");
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
    cW.set_controller(controller);
    cW.setModal(true);
    cW.exec();
}

void menu::on_validateButton_clicked()
{
    validation vW;
    vW.set_controller(controller);
    vW.setModal(true);
    vW.exec();
}
