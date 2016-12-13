//
// Created by ilya on 23.10.16.
//

#ifndef DIGITAL_WATERMARKING_VIEW_H
#define DIGITAL_WATERMARKING_VIEW_H

class Controller;

struct View {
    Controller* controller;
    virtual void setController(Controller* c_){ controller = c_;};
    virtual void viewMain() = 0;
};


#endif //DIGITAL_WATERMARKING_VIEW_H
