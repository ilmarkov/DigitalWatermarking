//
// Created by ilya on 29.11.16.
//

#ifndef WATERMARKENGINE_QTCONTROLLER_H
#define WATERMARKENGINE_QTCONTROLLER_H

#include "Controller.h"
#include "../model/DWTDugad.h"

struct QTController: Controller{
private:

public:
    QTController(Model *m, View *v) : Controller(m, v) {}

    Model* getModel(){
        return model;
    }

    virtual void execute() {
        Watermark_Plugin* plugin = new DWTDugad();
        model->setPlugin(plugin);
        model->embed("/home/ilya/ClionProjects/DigitalWatermarking/Debug/my.sig",
                     "/home/ilya/ClionProjects/DigitalWatermarking/Debug/ref_image.jpg",
                     "/home/ilya/ClionProjects/DigitalWatermarking/Debug");
        view->viewMain();
        delete plugin;
    }


};

#endif //WATERMARKENGINE_QTCONTROLLER_H
