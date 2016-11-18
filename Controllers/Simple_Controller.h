//
// Created by ilya on 17.11.16.
//

#include <model/DWTDugad.h>
#include "Controller.h"

#ifndef WATERMARKENGINE_SIMPLE_CONTROLLER_H
#define WATERMARKENGINE_SIMPLE_CONTROLLER_H

#endif //WATERMARKENGINE_SIMPLE_CONTROLLER_H

struct Simple_Controller: public Controller{
    Simple_Controller(Model* m, View* v):Controller(m, v){
    }

    virtual void execute() override {
        Watermark_Plugin* plugin = new DWTDugad();
        model->setPlugin(plugin);
        const char* filename = model->generate_signature("somepass", "my.sig");
        const char* embedded =  model->embed(filename, "../images/ref_image.jpg", "result.jpg");
        std::cout << model->verify(embedded, filename);
    }

};