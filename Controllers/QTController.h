//
// Created by ilya on 29.11.16.
//

#ifndef WATERMARKENGINE_QTCONTROLLER_H
#define WATERMARKENGINE_QTCONTROLLER_H

#include "Controller.h"
#include "../model/DWTDugad.h"

struct QTController: Controller{
private:
    const char* signature_path;
    const char* image_path;
    const char* watermark_name;
    bool embed_flag = false;

    const char* key;
    const char* sig_path;
    bool sig_flag = false;

    const char* imgPath;
    const char* sigPath;
    bool validate_flag = false;
public:
    QTController(Model *m, View *v) : Controller(m, v) {}

    virtual void execute() {
        Watermark_Plugin* plugin = new DWTDugad();
        model->setPlugin(plugin);
        view->viewMain();
        delete plugin;
    }

    void set_create_sig(const char* key, const char* sig_path){
        this->key = key;
        this->sig_path = sig_path;
        sig_flag = true;
    }

    void commit_create_sig(){
        if (sig_flag){
            model->generate_signature(key,sig_path);
            sig_flag = false;
        }
    }


    void set_validating(const char* imgPath, const char* sigPath){
        this->imgPath = imgPath;
        this->sigPath = sigPath;
        validate_flag = true;
    }

    int commit_validate(){
        if (validate_flag){
            int res = model->verify(imgPath, sigPath);
            validate_flag = false;
            return res;
        }
    }

    void set_embedding(const char* signature_path, const char* image_path, const char* watermark_name){
        this->signature_path = signature_path;
        this->image_path = image_path;
        this->watermark_name =watermark_name;
        embed_flag = true;
    }

    void commit_watermark_embed(){
        if (embed_flag){
            model->embed(signature_path, image_path, watermark_name);
            embed_flag = false;
        }
    }


};

#endif //WATERMARKENGINE_QTCONTROLLER_H
