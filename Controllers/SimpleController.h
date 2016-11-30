//
// Created by ilya on 17.11.16.
//



#ifndef WATERMARKENGINE_SIMPLE_CONTROLLER_H
#define WATERMARKENGINE_SIMPLE_CONTROLLER_H

#include "Controller.h"
#include "../model/DWTDugad.h"


struct SimpleController: public Controller{
    SimpleController(Model* m, View* v):Controller(m, v){
    }

    virtual void execute() override {
        Watermark_Plugin* plugin = new DWTDugad();
        model->setPlugin(plugin);
        const char* filename = model->generate_signature("somepass", "my.sig");
        const char* embedded =  model->embed("my.sig", "ref_image.jpg", "cropwm.jpg");
        std::cout << model->verify("result.jpg", "my.sig");
    }

};

#endif //WATERMARKENGINE_SIMPLE_CONTROLLER_H