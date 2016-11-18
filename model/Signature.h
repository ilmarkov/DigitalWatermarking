//
// Created by ilya on 08.11.16.
//

#ifndef WATERMARKENGINE_SIGNATURE_H
#define WATERMARKENGINE_SIGNATURE_H


#include <cstdio>
#include <iosfwd>
#include <streambuf>
#include <istream>
#include <fstream>


double my_rand();

class Signature {
    /**
    * Signature stamp
    */
    const char* stamp = "DGSG";
    /*
     * Stamp length
     */
    int len = 4;
    /**
     * Length of the watermark (in bits)
     */
    int watermark_length = 1000;

    /**
     * Wavelet filter method
     */
    int wavelet_filter_method = 2;

    /**
     * Filter number
     */
    int filter_id = 1;

    /**
     * Embedding level
     */
    int decomposition_level = 3;

    /**
     * Alpha factor
     */
    double alpha = 0.2;

    /**
     * Casting threshold
     */
    double casting_threshold = 40.0;

    /**
     * Detection threshold
     */
    double detection_threshold = 50.0;

    /**
     * Watermark data
     */
    double* watermark = NULL;

public:

    Signature(){
        double x, x1, x2;
        watermark = new double[watermark_length];

        for(int i = 0; i < watermark_length; i += 2)
        {
            do
            {
                x1 = 2.0 * my_rand() - 1.0;
                x2 = 2.0 * my_rand() - 1.0;
                x = x1 * x1 + x2 * x2;
            }
            while(x >= 1.0);
            x1 *= sqrt((-2.0) * log(x) / x);
            x2 *= sqrt((-2.0) * log(x) / x);

            watermark[i] = x1;
            watermark[i + 1] = x2;
        }
    }

    Signature(std::istream& sig_data){
        sig_data.ignore(len);
        sig_data >> watermark_length;
        sig_data >> wavelet_filter_method;
        sig_data >> filter_id;
        sig_data >> decomposition_level;
        sig_data >> alpha;
        sig_data >> casting_threshold;
        sig_data >>detection_threshold;

        watermark = new double[watermark_length];

        for (int i = 0; i < watermark_length; ++i) {
            sig_data >> watermark[i];
        }
    }

    void get_sig_data(const char *file_name){
        std::ofstream of;
        of.open(file_name, std::ofstream::out);
        of << stamp << " ";
        of << watermark_length << " ";
        of << filter_id << " ";
        of << decomposition_level << " ";
        of << alpha << " ";
        of << casting_threshold << " ";
        of << detection_threshold << " ";

        for (int i = 0; i < watermark_length; ++i) {
            of << watermark[i] << " ";
        }
        of.flush();
        of.close();
    }

    int getWavelet_filter_method() const {
        return wavelet_filter_method;
    }

    int getFilter_id() const {
        return filter_id;
    }

    int getDecomposition_level() const {
        return decomposition_level;
    }

    int getWatermark_length() const {
        return watermark_length;
    }

    double getAlpha() const {
        return alpha;
    }

    double getDetection_threshold() const {
        return detection_threshold;
    }

    double getCasting_threshold() const {
        return casting_threshold;
    }

    double *getWatermark() const {
        return watermark;
    }
};

double my_rand(){
    return static_cast <double > (rand()) / static_cast <double > (RAND_MAX);
}

#endif //WATERMARKENGINE_SIGNATURE_H
