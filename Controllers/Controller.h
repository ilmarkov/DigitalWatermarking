//
// Created by ilya on 23.10.16.
//

#ifndef DIGITAL_WATERMARKING_CONTROLLER_H
#define DIGITAL_WATERMARKING_CONTROLLER_H


#include "../model/Model.h"
#include "../Views/View.h"

class Controller {
    Model _model;
    View  _view;
public:
    Controller(Model m, View v):_model(m), _view(v){};
    virtual void execute() = 0;
};


#endif //DIGITAL_WATERMARKING_CONTROLLER_H
