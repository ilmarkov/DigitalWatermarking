//
// Created by ilya on 13.11.16.
//

#ifndef WATERMARKENGINE_MODEL_H
#define WATERMARKENGINE_MODEL_H

#include <fstream>
#include <iostream>
#include "Watermark_Plugin.h"

struct Model{
    Watermark_Plugin* plugin;
    Model(){}
    virtual const char * embed(std::string msg_filename, std::string cover_filename, std::string stego_filename) {
        return plugin->embed(msg_filename, cover_filename, stego_filename).c_str();
    }

    virtual bool verify(std::string stego_filename, std::string orig_sig_data) {
        std::ifstream is(orig_sig_data);
        std::stringstream ss;
        plugin->extract(stego_filename, is, ss);
        double correlation = plugin->get_watermark_correlation(is, ss);
        return (correlation > plugin->get_high_watermark_level());
    }

    virtual std::string generate_signature(std::string pass, std::string file_name = NULL){
        if (file_name.empty())
            file_name = "MySig.sig";
        plugin->generate_signature(pass, file_name);
        return file_name;
    }
    void setPlugin(Watermark_Plugin *plugin) {
        Model::plugin = plugin;
    }
};
#endif //WATERMARKENGINE_MODEL_H
