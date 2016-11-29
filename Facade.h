//
// Created by ilya on 23.10.16.
//

#ifndef DIGITAL_WATERMARKING_FACADE_H
#define DIGITAL_WATERMARKING_FACADE_H



#include "Controllers/SimpleController.h"
#include <memory>


class Facade {
public:
    void run(){
        std::unique_ptr<Model> m(new Model());
        std::unique_ptr<View> v(new QTView());
        Controller* c = new QTController(m.get(), v.get());
        v->setController(c);
        c->execute();
    }
};


#endif //DIGITAL_WATERMARKING_FACADE_H
