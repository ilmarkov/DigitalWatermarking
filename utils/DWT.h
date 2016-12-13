//
// Created by ilya on 07.11.16.
//

#ifndef WATERMARKENGINE_DWT_H
#define WATERMARKENGINE_DWT_H


#include <map>
#include "DWTUtil.h"
#include "ParserUtil.h"

class DWT {

    /**
     * Master map of filters
     */
    static std::map<int, DWTUtil::FilterGH> filter_GH_map;

    /**
     * URI for the filter file
     */
    const char* filter_file = "../utils/filters.xml";

    /**
     * List of loaded filters
     */
    DWTUtil::FilterGH* filters;

    /**
     * Wavelet filtering method
     */
    int method = 0;

    /**
     * No. of columns in the image
     */
    int cols = 0;

    /**
     * No. of rows in the image
     */
    int rows = 0;

    /**
     * Wavelet decomposition level
     */
    int level = 0;



public:
    /**
     * Default constructor
     *
     * @param cols Image width
     * @param rows Image height
     * @param filterID Filter ID to use
     * @param level Decomposition level
     * @param method Wavelet filtering method
     */
    DWT(int cols_, int rows_, int filter_ID, int level_, int method_){
        if (DWT::filter_GH_map.empty()){
            DWT::filter_GH_map = parse(filter_file);
        }
        filters = new DWTUtil::FilterGH[level_ + 1];

        for(int i = 0; i <= level_; i++)
        {
            filters[i] = DWT::filter_GH_map.at(filter_ID);
        }
        cols = cols_;
        rows = rows_;
        level = level_;
        method = method_;
    }


    /**
     * Method to perform forward DWT on the pixel data
     *
     * @param pixels Image pixel data
     * @return Image tree data after DWT
     */
    template <typename T>
    ImageTree forward_DWT(T *pixels){
        MyImage image(cols, rows);


        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                image.setPixel(j, i, pixels[i * cols + j]);
            }
        }


        return DWTUtil::waveletTransform(image, level, filters, method);
    }


    /**
     * Method to perform forward DWT (WP) on the pixel data
     *
     * @param pixels Image pixel data
     * @return Image tree data after DWT
     */
    template <typename T>
    ImageTree forward_DWT_WP(T *pixels){
        MyImage image(cols, rows);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                image.setPixel(j,i, pixels[i * cols + j]);
            }
        }
        return DWTUtil::waveletTransformWp(image, 0, level, filters, method);
    }

    /**
     * Utility macro to limit the value within [0,255] range
     *
     * @param p Input value
     * @return Limited value
     */
    #define RANGE(p) ((p > 255) ? 255 : (p < 0) ? 0 : p)

    /**
     * Method to perform inverse DWT to get back the pixel data
     *
     * @param dwts DWT data as image tree
     * @param pixels Image pixel data
     */
    template <typename T>
    void inverse_DWT(ImageTree &dwts, T *pixels){

        MyImage image = DWTUtil::inv_transform(dwts, filters,
                                                static_cast<DWTUtil::FilterMethod >(method + 1));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                pixels[i*cols + j] = RANGE(image.getPixel(j, i) + 0.5);
            }
        }
    }
};

std::map<int, DWTUtil::FilterGH> DWT::filter_GH_map;

#endif //WATERMARKENGINE_DWT_H
