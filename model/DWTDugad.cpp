//
// Created by ilya on 08.11.16.
//

#include <utils/DWT.h>
#include "DWTDugad.h"
#include "../lib/CImg.h"

using namespace std;
using namespace cimg_library;


void DWTDugad::generate_signature(std::string passphrase, std::string file_name, std::string dir_name) {

    if (passphrase.empty()){
        srand(Watermark_Plugin::DEFAULT_HASH);
    }
    else {
        std::hash<std::string> str_hash;
        srand(str_hash(std::string(passphrase)));
    }
    if (file_name.empty())
        file_name = "MySig.sig";
    if (!dir_name.empty())
        file_name = dir_name + "/" + file_name;
    Signature sig;
    sig.get_sig_data(file_name.c_str());
}



string DWTDugad::embed(string msg_filename, string cover_filename, string stego_filename) {
    CImg<pixel_type> img(cover_filename.c_str());
    pixel_type* luminance = NULL; //pointer to pixel size col*rows*depth, depth = 1

    int imgType = 0;
    int cols = 0;
    int rows = 0;

    if (cover_filename.empty())
        throw ProjectException("No file to embed in is chosen");


    cols = img._width;
    rows = img._height;

    luminance = img.RGBtoYUV().data(0,0,0,0);

    for (int j = 0; j < cols * rows; ++j) {
        luminance[j] =  ceil(254 * luminance[j]);
    }

    if (msg_filename.empty())
        throw ProjectException("No Signature file provided");

    std::ifstream msg_stream(msg_filename);

    Signature sig(msg_stream);




    DWT dwt(cols, rows, sig.getFilter_id(), sig.getDecomposition_level(), sig.getWavelet_filter_method());

    ImageTree dwt_tree  = dwt.forward_DWT<pixel_type>(luminance);
    ImageTree* s = &dwt_tree;




    for (int i = 0; i < sig.getDecomposition_level(); ++i) {
        wm_subBand(s->getHorizontal().getImage(), sig.getWatermark(), sig.getWatermark_length(), sig.getAlpha(), sig.getCasting_threshold());
        wm_subBand(s->getVertical().getImage(), sig.getWatermark(), sig.getWatermark_length(), sig.getAlpha(), sig.getCasting_threshold());
        wm_subBand(s->getDiagonal().getImage(), sig.getWatermark(), sig.getWatermark_length(), sig.getAlpha(), sig.getCasting_threshold());
        s = &s->getCoarse();
    }


    dwt.inverse_DWT(dwt_tree, luminance);



    for (int j = 0; j < cols * rows; ++j) {
        luminance[j] /= 254;
    }



    img.YUVtoRGB();

    const size_t last_slash_idx = cover_filename.rfind('/');

    std::string name;

    if (std::string::npos != last_slash_idx)
    {
        name = cover_filename.substr(last_slash_idx + 1);
    }
    if (!name.empty())
        stego_filename = stego_filename + "/new_" + name;
    else{
        stego_filename = "new_" + cover_filename;
    }


    img.save_jpeg(stego_filename.c_str());

    return stego_filename;
}

void DWTDugad::extract(string stego_filename, std::istream &orig_sig_data, std::ostream &output) {
    pixel_type * luminance = NULL;
    int cols = 0, rows = 0;

    CImg<pixel_type> img(stego_filename.c_str());

    cols = img._width;
    rows = img._height;

    luminance = img.RGBtoYUV().data(0,0,0,0);

    for (int j = 0; j < cols * rows; ++j) {
        luminance[j] =  ceil(254 * luminance[j]);
    }

    Signature sig(orig_sig_data);

    DWT dwt(cols, rows, sig.getFilter_id(), sig.getDecomposition_level(), sig.getWavelet_filter_method());
    ImageTree dwt_tree = dwt.forward_DWT<pixel_type>(luminance);
    ImageTree& s = dwt_tree;

    output << sig.getDecomposition_level() << " ";

    output << sig.getAlpha() << " ";

    double* vals = new double[3];

    for (int i = 0; i < sig.getDecomposition_level(); ++i) {
        inv_wm_subBand(s.getHorizontal().getImage(), sig.getWatermark(), sig.getWatermark_length(),
                              sig.getDetection_threshold(), vals);
        output << vals[0] << " " << vals[1] << " " << vals[2] << " ";

        inv_wm_subBand(s.getVertical().getImage(), sig.getWatermark(), sig.getWatermark_length(),
                              sig.getDetection_threshold(), vals);
        output << vals[0] << " " << vals[1] << " " << vals[2] << " ";

        inv_wm_subBand(s.getDiagonal().getImage(), sig.getWatermark(), sig.getWatermark_length(),
                              sig.getDetection_threshold(), vals);
        output << vals[0] << " " << vals[1] << " " << vals[2] << " ";
    }
    delete []vals;
    for (int j = 0; j < cols * rows; ++j) {
        luminance[j] /= 254;
    }
    img.YUVtoRGB();
}

double DWTDugad::get_watermark_correlation(std::istream &orig_sig_data, std::istream &watermark_data) {
    int level = 0;
    int n = 0;
    int ok = 0;
    double m = 0;
    double z = 0.0, v = 0.0, alpha = 0.0;
    double diff = 0.0;

    watermark_data >> level;
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

