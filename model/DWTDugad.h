//
// Created by ilya on 08.11.16.
//

#ifndef WATERMARKENGINE_DWTDUGAD_H
#define WATERMARKENGINE_DWTDUGAD_H


#include <cmath>
#include "Watermark_Plugin.h"
#include "../utils/MyImage.h"
#include "Signature.h"

class DWTDugad: public Watermark_Plugin {
public:
    DWTDugad(){}
    virtual CImg<pixel_type>*
    embed(char *msg_filename, char *cover_filename, char *stego_filename) override;

    virtual char *extract(char *stego_filename, std::istream orig_sig_data) override;

    std::ofstream generate_signature(char* file_name);

private:
    void wm_subBand(MyImage* img, double* wm, int n, double a,double threshold){
        for (int i = 0; i < img->getWidth() * img->getHeight(); ++i) {
            if (fabs(img->getData()[i]) > threshold){
                img->getData()[i] += (a * fabs(img->getData()[i]) * wm[i%n]);
            }
        }
    }

    double* inv_wm_subBand(MyImage* img, double* wm, int n, double threshold, double* val){

        std::fill_n(val, 3, 0.0);

        for(int i = 0; i < img->getWidth() * img->getHeight(); i++)
        {
            if(img->getData()[i] > threshold)
            {
                val[1] += (img->getData()[i] * wm[i % n]);
                val[2] += fabs(img->getData()[i]);
                val[0]++;
            }
        }

        return val;
    }
};


#endif //WATERMARKENGINE_DWTDUGAD_H
