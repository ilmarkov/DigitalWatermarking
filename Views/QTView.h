//
// Created by ilya on 29.11.16.
//

#ifndef WATERMARKENGINE_QTVIEW_H
#define WATERMARKENGINE_QTVIEW_H

#include <QtWidgets/QApplication>
#include <Interface/menu.h>
#include "View.h"

struct QTView: View{
    int argc;
    char **argv;

    QTView(int argc, char **argv){
        QTView::argc = argc;
        QTView::argv = argv;
    }

    virtual void viewMain(){
        QApplication a(argc, argv);
        menu w;
        w.set_controller((QTController*)controller);
        w.show();
        a.exec();
    }
};

#endif //WATERMARKENGINE_QTVIEW_H
