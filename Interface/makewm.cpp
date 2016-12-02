#include "ui_makewm.h"
#include <QTextStream>
#include "makewm.h"

makeWM::makeWM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::makeWM)
{
    ui->setupUi(this);

    QIcon icon;
    icon.addFile(":/resources/img/create.png");
    setWindowTitle("Create new signature");
    setWindowIcon(icon);
}

makeWM::~makeWM()
{
    delete ui;
}

void makeWM::on_browseKey_clicked()
{
    QString keyPath = QFileDialog::getOpenFileName(this, "Open key", "C://", "Text file (*.txt)");
    ui->pathKey->setText(keyPath);
}

void makeWM::on_browseNewMark_clicked()
{
    QDir newMarkPath = QFileDialog::getOpenFileName(this, "Choose file for new signature", "C://", "Signature (*.sig)");
    ui->pathNewMark->setText(newMarkPath.absolutePath());
}

void makeWM::on_ok_clicked()
{
    QString key = ui->editKey->text();
    QString keyPath = ui->pathKey->text();
    QString newMarkPath = ui->pathNewMark->text();

    // только одно из двух полей (editKey, pathKey) может быть заполнено (автоматически затирается первое поле при изменении второго)
    if(key != "" && newMarkPath != "")
    {
        //
        // создании водяного знака тут
        // необходимые параметры: key, newMarkPath
        //
        controller->getModel()->generate_signature(key.toStdString(), newMarkPath.toStdString());
        QMessageBox::about(this, "Success", "Watermark has been created!");
        close();
    }
    else if(keyPath != "" && newMarkPath != "")
    {
        QString extractedKey = "";
        QFile file(keyPath);
        QTextStream stream(&file);

        if(!file.open(QIODevice::ReadOnly))
            QMessageBox::critical(0, "Error", file.errorString());

        while(!stream.atEnd())
            extractedKey = stream.readLine();

        file.close();
        //
        // создании водяного знака тут
        // необходимые параметры: fileKey, newMarkPath
        //
        controller->getModel()->generate_signature(extractedKey.toStdString(), newMarkPath.toStdString());
        QMessageBox::about(this, "Success", "Watermark has been created!");
        close();
    }
    else
    {
        QMessageBox::warning(this, "Fail", "Specify all parameters, please!");
    }
}

void makeWM::on_cancel_clicked()
{
    close();
}
