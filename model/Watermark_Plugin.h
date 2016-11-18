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
protected:
    static const int DEFAULT_HASH = 964923;
public:
    /**
     * Method to embed the message into the cover data
     *
     * @param msg_filename Name of the message file. If this value is provided, then the filename should be embedded in
     *        the cover data
     * @param cover_filename Name of the cover file
     * @param stego_filename Name of the output stego file, if NULL, name generated as cober +_mark
     * @return name of new file
     * @throws ProjectException
     */
    virtual const char * embed(const char *msg_filename, const char *cover_filename, const char *stego_filename) = 0;

    /**
     * Method to extract the message from the stego data
     *
     * @param stego_filename Name of the stego file
     * @param orig_sig_data signature data stream for watermark
     * @return Extracted message in stream
     * @throws ProjectException
     */
    virtual std::iostream & extract(const char *stego_filename, std::istream &orig_sig_data) = 0;


    /**
     * Method to generate the signature data
     *
     * @return Signature data
     * @throws ProjectException
     */
    virtual void generate_signature(const char *passphrase, const char *filename) = 0;


    /**
     * Method to check the correlation between original signature and the extracted watermark
     *
     * @param orig_sig_data Original signature data
     * @param watermark_data Extracted watermark data
     * @return Correlation
     * @throws ProjectException
     */
    virtual double get_watermark_correlation(std::istream &orig_sig_data, std::istream &watermark_data) = 0;

    /**
     * Method to get correlation value which above which it can be considered that watermark strength is high (default
     * to 0.5 which is safe for general watermarking)
     *
     * @return High watermark
     */
    double get_high_watermark_level() {
        return 0.5;
    }

    /**
     * Method to get correlation value which below which it can be considered that watermark strength is low (default to
     * 0.2 which is safe for general watermarking)
     *
     * @return Low watermark
     */
    double get_low_watermark_level() {
        return 0.2;
    }
};


#endif //WATERMARKENGINE_WATERMARK_PLUGIN_H
