#include "makewm.h"
#include "ui_makewm.h"
#include "creation.h"
#include "makewm.h"
#include "menu.h"
#include "validation.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

makeWM::makeWM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::makeWM)
{
    ui->setupUi(this);

    QIcon icon;
    icon.addFile(":/resources/img/create.png");
    setWindowTitle("Make new watermark");
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
    QDir newMarkPath = QFileDialog::getExistingDirectory(this, "Choose directory for new watermark", "C://", QFileDialog::ShowDirsOnly);
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
        //TODO: EDIT
        controller.set_key_mark_path(key.c_str, newmarkpath);
        controller.commit();
        QMessageBox::about(this, "Success", "Watermark has been created!");
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
        QMessageBox::about(this, "Success", "Watermark has been created!");
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
