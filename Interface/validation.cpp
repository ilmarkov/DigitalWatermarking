
#include "ui_validation.h"
#include "validation.h"

validation::validation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::validation)
{
    ui->setupUi(this);
    QIcon icon;
    icon.addFile(":/resources/img/validate.png");
    setWindowTitle("Validation");
    setWindowIcon(icon);
}

validation::~validation()
{
    delete ui;
}

void validation::on_browseImage_2_clicked()
{
    QString imgPath = QFileDialog::getOpenFileName(this, "Open image", "C://", "Images (*.jpg)"); //добавить еще расширения, если надо
    ui->pathImage_2->setText(imgPath);
}

void validation::on_browseMark_2_clicked()
{
    QString markPath = QFileDialog::getOpenFileName(this, "Open watermark", "C://", "Signature (*.sig)"); //добавить фильтр для расширение водяного знака
    ui->pathMark_2->setText(markPath);
}

void validation::on_ok_clicked()
{
    QString imgPath = ui->pathImage_2->text();
    QString markPath = ui->pathMark_2->text();

    if(imgPath != "" && markPath != "")
    {
        //
        // проверка водяного знака тут
        // необходимые параметры: img_path_validate, markPath
        int res = controller->getModel()->verify(imgPath.toStdString(), markPath.toStdString());
        // ниже добавить функцию проверки в switch (вернула 1 - ок, 0 - не ок)
        switch(res)
        {
            case 1: QMessageBox::about(this, "Result", "Watermark is valid!");
                break;
            case 0: QMessageBox::critical(this, "Result", "Watermark is not valid!");
                break;
        }
    }
    else
    {
        QMessageBox::warning(this, "Error", "Specify all parameters, please!");
    }
}

void validation::on_cancel_clicked()
{
    close();
}
