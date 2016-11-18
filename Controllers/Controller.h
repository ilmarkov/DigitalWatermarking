//
// Created by ilya on 23.10.16.
//

#ifndef DIGITAL_WATERMARKING_CONTROLLER_H
#define DIGITAL_WATERMARKING_CONTROLLER_H


#include <Views/View.h>
#include <model/Model.h>

class Controller {
protected:
    Model* model;
    View*  view;
public:
    Controller(Model* m, View* v): model(m), view(v){};
    virtual void execute() = 0;
};


#endif //DIGITAL_WATERMARKING_CONTROLLER_H
