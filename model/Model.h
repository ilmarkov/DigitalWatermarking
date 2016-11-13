//
// Created by ilya on 13.11.16.
//

#ifndef WATERMARKENGINE_MODEL_H
#define WATERMARKENGINE_MODEL_H

#include "DWTDugad.h"

struct Model{
    Watermark_Plugin* plugin;
    Model(){
        plugin = new DWTDugad();
    }
    void run(){}
};
#endif //WATERMARKENGINE_MODEL_H
