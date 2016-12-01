//
// Created by ilya on 23.10.16.
//

#ifndef DIGITAL_WATERMARKING_FACADE_H
#define DIGITAL_WATERMARKING_FACADE_H

#include "Views/QTView.h"
//#include "Controllers/QTController.h"
#include "Controllers/SimpleController.h"
#include <memory>


class Facade {
public:
    void run(int argc, char** argv){
        std::unique_ptr<Model> m(new Model());
//        std::unique_ptr<View> v(new QTView(argc, argv));
        std::unique_ptr<View> v(new View());
        Controller* c = new SimpleController(m.get(), v.get());
//        Controller* c = new QTController(m.get(), v.get());
//        v->setController(c);
        c->execute();
    }
};


#endif //DIGITAL_WATERMARKING_FACADE_H
