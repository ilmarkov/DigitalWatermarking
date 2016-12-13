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
    virtual std::string
    embed(std::string msg_filename, std::string cover_filename, std::string stego_filename);

    virtual void extract(std::string stego_filename, std::istream &orig_sig_data, std::ostream &output);

    void generate_signature(std::string passphrase, std::string file_name, std::string dir_name);

    virtual double get_watermark_correlation(std::istream &orig_sig_data, std::istream &watermark_data);

private:
    /*!
     * Embed watermark in image
     * @param img, image embed in
     * @param wm, watermark
     * @param n module for subBand
     * @param a alpha, coeff for subBand
     * @param threshold
     * */
    void wm_subBand(MyImage &img, double *wm, int n, double a, double threshold){
        for (int i = 0; i < img.getWidth() * img.getHeight(); ++i) {
            if (fabs(img.getData()[i]) > threshold){
                img.getData()[i] += (a * fabs(img.getData()[i]) * wm[i % n]);
            }
        }
    }

    /*!
    * Get watermark from image
    * @param img, image embed in
    * @param wm, watermark
    * @param n module for subBand
    * @param a alpha, coeff for subBand
    * @param threshold
    * */
    void inv_wm_subBand(MyImage &img, double *wm, int n, double threshold, double *val){

        std::fill_n(val, 3, 0.0);

        for(int i = 0; i < img.getWidth() * img.getHeight(); i++)
        {
            double v = img.getData()[i];
            if(img.getData()[i] > threshold)
            {
                val[1] += (img.getData()[i] * wm[i % n]);
                val[2] += fabs(img.getData()[i]);
                val[0]++;
            }
        }
    }
};


#endif //WATERMARKENGINE_DWTDUGAD_H
