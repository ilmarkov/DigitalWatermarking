//
// Created by ilya on 08.11.16.
//

#include <utils/DWT.h>
#include "DWTDugad.h"


//TODO: Connection with user space(filenames, etc.)

std::ofstream DWTDugad::generate_signature(char *file_name) {
    srand((unsigned int)time(0));
    Signature sig;
    return sig.get_sig_data(file_name);
}



CImg<pixel_type>* DWTDugad::embed(char *msg_filename, char *cover_filename, char *stego_filename) {
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
    return img;
}

char * DWTDugad::extract(char *stego_filename, std::istream orig_sig_data) {
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

}