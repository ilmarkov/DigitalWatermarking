#include "menu.h"
#include "makewm.h"
#include "creation.h"
#include "validation.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu w;
    w.show();

    return a.exec();
}
