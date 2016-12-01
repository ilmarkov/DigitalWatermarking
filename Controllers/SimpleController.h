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
        std::string filename = model->generate_signature("hahaha", "my1.sig");
        const char* embedded =  model->embed("/home/ilya/ClionProjects/DigitalWatermarking/Debug/my1.sig",
                                             "/home/ilya/ClionProjects/DigitalWatermarking/Debug/ref_image.jpg",
                                             "/home/ilya/ClionProjects/DigitalWatermarking/Debug");
        std::cout << model->verify("/home/ilya/ClionProjects/DigitalWatermarking/Debug/new_ref_image.jpg",
                                   "/home/ilya/ClionProjects/DigitalWatermarking/Debug/my.sig");
    }

};

#endif //WATERMARKENGINE_SIMPLE_CONTROLLER_H