//
// Created by ilya on 23.10.16.
//

#ifndef DIGITAL_WATERMARKING_FACADE_H
#define DIGITAL_WATERMARKING_FACADE_H


#include "Models/Model.h"
#include "Views/View.h"
#include "Controllers/Controller.h"

class Facade {
public:
    void run(){
        Model m;
        View v;
        Controller c(m,v);
        c.execute();
    }
};


#endif //DIGITAL_WATERMARKING_FACADE_H
