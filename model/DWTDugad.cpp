//
// Created by ilya on 08.11.16.
//

#include <utils/DWT.h>
#include "DWTDugad.h"


//TODO: Connection with user space(filenames, etc.)

void DWTDugad::generate_signature(const char *file_name, const char *passphrase) {

    if (passphrase == NULL || strcmp(passphrase, "")){
        srand(Watermark_Plugin::DEFAULT_HASH);
    }
    else {
        std::hash<std::string> str_hash;
        srand(str_hash(std::string(passphrase)));
    }


    Signature sig;
    sig.get_sig_data(file_name);
}



const char * DWTDugad::embed(const char *msg_filename, const char *cover_filename, const char *stego_filename) {
    CImg<pixel_type> *img = NULL;
    pixel_type* luminance = NULL; //pointer to pixel size col*rows*depth, depth = 1
    DWT* dwt = NULL;
    ImageTree* dwt_tree = NULL;
    ImageTree* s = NULL;
    Signature* sig = NULL;
    int imgType = 0;
    int cols = 0;
    int rows = 0;

    if (!cover_filename)
        throw ProjectException("No file to embed in is chosen");

    img = new CImg<pixel_type>(cover_filename);

    cols = img->_width;
    rows = img->_height;

    luminance = img->RGBtoYUV().data(0,0,0,0);

    if (!msg_filename)
        throw ProjectException("No Signature file provided");

    std::ifstream msg_stream(msg_filename);
    sig = new Signature(msg_stream);

    dwt = new DWT(cols, rows, sig->getFilter_id(), sig->getDecomposition_level(), sig->getWavelet_filter_method());
    dwt_tree = dwt->forward_DWT<pixel_type>(luminance);
    s = dwt_tree;

    for (int i = 0; i < sig->getDecomposition_level(); ++i) {
        wm_subBand(s->getHorizontal()->getImage(), sig->getWatermark(), sig->getWatermark_length(), sig->getAlpha(), sig->getCasting_threshold());
        wm_subBand(s->getVertical()->getImage(), sig->getWatermark(), sig->getWatermark_length(), sig->getAlpha(), sig->getCasting_threshold());
        wm_subBand(s->getDiagonal()->getImage(), sig->getWatermark(), sig->getWatermark_length(), sig->getAlpha(), sig->getCasting_threshold());
        s = s->getCoarse();
    }

    dwt->inverse_DWT(dwt_tree, luminance);

    img->YUVtoRGB();
    img->save_jpeg(stego_filename);
    return stego_filename;
}

std::iostream & DWTDugad::extract(const char *stego_filename, std::istream &orig_sig_data) {
    std::stringstream ss;
    CImg<pixel_type>* img = NULL;
    DWT* dwt = NULL;
    ImageTree* dwt_tree = NULL , *s = NULL;
    Signature* sig = NULL;
    pixel_type * luminance = NULL;
    int cols = 0, rows = 0;

    img = new CImg<pixel_type >(stego_filename);

    cols = img->_width;
    rows = img->_height;

    luminance = img->get_RGBtoYUV().data(0,0,0,0);

    sig = new Signature(orig_sig_data);

    dwt = new DWT(cols, rows, sig->getFilter_id(), sig->getDecomposition_level(), sig->getWavelet_filter_method());
    dwt_tree = dwt->forward_DWT(luminance);
    s = dwt_tree;

    ss << sig->getDecomposition_level() << " ";
    ss << sig->getAlpha() << " ";

    double vals[3];

    for (int i = 0; i < sig->getDecomposition_level(); ++i) {
        inv_wm_subBand(s->getHorizontal()->getImage(), sig->getWatermark(), sig->getWatermark_length(),
                              sig->getDetection_threshold(), vals);
        ss << vals[0] << " " << vals[1] << " " << vals[2];

        inv_wm_subBand(s->getVertical()->getImage(), sig->getWatermark(), sig->getWatermark_length(),
                              sig->getDetection_threshold(), vals);
        ss << vals[0] << " " << vals[1] << " " << vals[2];

        inv_wm_subBand(s->getDiagonal()->getImage(), sig->getWatermark(), sig->getWatermark_length(),
                              sig->getDetection_threshold(), vals);
        ss << vals[0] << " " << vals[1] << " " << vals[2];
    }
    return ss;
}

double DWTDugad::get_watermark_correlation(std::istream &orig_sig_data, std::istream &watermark_data) {
    int level = 0;
    int n = 0;
    int ok = 0;
    int m = 0;
    double z = 0.0, v = 0.0, alpha = 0.0;
    double diff = 0.0;

    watermark_data >> level; //TODO: question what first???
    watermark_data >> alpha;

    n = level * 3;

    for (int i = 0; i < level; ++i) {

        // HL subband
        watermark_data >> m >> z >> v;

        if (m != 0){
            ok += (z > v * alpha / 1.0) ? 1 : 0;
            diff += ((z - v * alpha) / (1.0 * m));
        }
        else {
            n--;
        }

        // LH subband
        watermark_data >> m >> z >> v;
        if (m != 0)
        {
            ok += (z > v * alpha / 1.0) ? 1 : 0;
            diff += ((z - v * alpha) / (1.0 * m));
        }
        else {
            n--;
        }

        // HH subband
        watermark_data >> m >> z >> v;
        if (m != 0){
            ok += (z > v * alpha / 1.0) ? 1 : 0;
            diff += ((z - v * alpha) / (1.0 * m));
        }
        else {
            n--;
        }

    }
    return ((double) ok) / n;
}

