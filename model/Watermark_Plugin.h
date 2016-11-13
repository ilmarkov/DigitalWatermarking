//
// Created by ilya on 07.11.16.
//

#ifndef WATERMARKENGINE_WATERMARK_PLUGIN_H
#define WATERMARKENGINE_WATERMARK_PLUGIN_H


#include <cstdlib>
#include "../lib/CImg.h"
#include "../utils/ProjectException.h"
#include <sstream>

typedef float pixel_type;


using namespace cimg_library;

class Watermark_Plugin {
public:
    /**
     * Method to embed the message into the cover data
     *
     * @param msg Message to be embedded
     * @param msg_filename Name of the message file. If this value is provided, then the filename should be embedded in
     *        the cover data
     * @param cover Cover data into which message needs to be embedded
     * @param cover_filename Name of the cover file
     * @param stego_filename Name of the output stego file
     * @return Stego data containing the message
     * @throws OpenStegoException
     */
    virtual CImg<pixel_type>* embed(char *msg_filename, char *cover_filename, char *stego_filename) = 0;

    /**
     * Method to extract the message from the stego data
     *
     * @param stego_filename Name of the stego file
     * @param orig_sig_data Optional signature data file for watermark
     * @return Extracted message
     * @throws OpenStegoException
     */
    virtual char *extract(char *stego_filename, std::istream orig_sig_data) = 0;


    /**
     * Method to generate the signature data
     *
     * @return Signature data
     * @throws OpenStegoException
     */
    virtual std::ofstream generate_signature(char*) = 0;


    /**
     * Method to check the correlation between original signature and the extracted watermark
     *
     * @param orig_sig_data Original signature data
     * @param watermark_data Extracted watermark data
     * @return Correlation
     * @throws OpenStegoException
     */
    double getWatermarkCorrelation(char* orig_sig_data, char* watermark_data){}


    /**
     * Watermarking transformation, set median pixel to quantization boundary
     */
private:
    double wm_transform(double alpha, double f1, double f2, double f3, int x)
    {
        double s = alpha * abs(f3 - f1) / 2.0;
        double l = (x != 0) ? (f1 + s) : f1;

        while((l + 2 * s) < f2)
        {
            l += 2 * s;
        }

        return ((f2 - l) < (l + 2 * s - f2)) ? l : (l + 2 * s);
    }

    /**
     * Inverse watermarking transformation, extract embedded bit, check quantization boundaries
     */
    int invWmTransform(double alpha, double f1, double f2, double f3)
    {
        double s = alpha * abs(f3 - f1) / 2.0;
        double l = f1;
        int x = 0;

        while(l < f2)
        {
            l += s;
            x++;
        }

        if(abs(l - s - f2) < abs(l - f2))
        {
            return (x + 1) % 2;
        }
        else
        {
            return x % 2;
        }
    }

};


#endif //WATERMARKENGINE_WATERMARK_PLUGIN_H
