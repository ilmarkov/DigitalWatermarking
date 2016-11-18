//
// Created by ilya on 23.10.16.
//

#ifndef DIGITAL_WATERMARKING_FACADE_H
#define DIGITAL_WATERMARKING_FACADE_H


#include "model/Model.h"
#include "Views/View.h"
#include "Controllers/Controller.h"

class Facade {
public:
    void run(){
        Model* m = new Model();
        View* v = new View();
        Controller* c = new SimpleController(m, v);
        v->setController(c);
        c->execute();
    }
};


#endif //DIGITAL_WATERMARKING_FACADE_H
