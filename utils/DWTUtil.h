//
// Created by ilya on 07.11.16.
//

#ifndef WATERMARKENGINE_DWTUTIL_H
#define WATERMARKENGINE_DWTUTIL_H

#include "ImageTree.h"
#include <vector>
#include <cmath>
#include "ProjectException.h"


namespace DWTUtil {

    typedef float Pixel;

    enum FilterMethod{cutoff=0,inv_cutoff,periodical,inv_periodical,mirror,inv_mirror};

    enum FilterType { FTNoSymm, FTSymm, FTAntiSymm};

    struct Filter {
    private:
        enum FilterType type;
        int hipass;
        Pixel * data = NULL;
        int start ,end;
    public:
        Filter(){}
        Filter(const Filter& filter);

        Filter&operator=(const Filter& filter);
        Pixel *getData() const;

        int getStart() const;

        int getEnd() const;

        int getHipass() const;

        void setHipass(int hipass);

        void setStart(int start);

        void setEnd(int end);

        void setType(std::string type);

        void setData(std::vector<Pixel>& vector);
    };

    enum FilterGHType { FTOrtho, FTBiOrtho, FTOther};

    struct FilterGH {
    private:
        int id;
        enum FilterGHType type;
        Filter g, h, gi, hi;
        const char *name;
    public:
        FilterGH(){};
        FilterGH(const FilterGH& filterGH );

        FilterGH& operator=(const FilterGH&);
        const Filter & getG() const;

        void setG(const Filter &g);

        const Filter & getH() const;

        void setH(const Filter &h);

        const Filter & getGi() const;

        void setGi(const Filter &gi);

        const Filter & getHi() const;

        void setHi(const Filter &hi);

        void setType(std::string type);

        void setId(int id);

        void setName(const char *name);

        FilterGHType getType() const;

        int getId() const;
    };


    ImageTree waveletTransform(MyImage orig_img, int level, FilterGH *filter_GH_list, int method);

    ImageTree waveletTransformWp(const MyImage &origImg, int current_level, int level, FilterGH *filter_GH_list,
                                 int method);

    MyImage inv_transform(ImageTree &tree, FilterGH *flt, enum FilterMethod method);

    void convolute_lines(MyImage &output_img, MyImage &input_img, const Filter &filter, int method);

    void convolute_rows(MyImage &output_img, MyImage &input_img, const Filter &filter, int method);

    void decomposition(MyImage &input_img, MyImage &coarse_img, MyImage &horizontal_img, MyImage &vertical_img,
                       MyImage &diagonal_img, const Filter &filterG, const Filter &filterH, int method);


    void inv_decomposition(MyImage &sumImg, MyImage &coarse_img, MyImage &horizontalImg, MyImage &vertical_img,
                           MyImage &diagonal_img, FilterGH filterGH, int method);

    int find_deepest_level(int width, int height);


    /*filters*/
    void filter_cutoff(MyImage &input_img, int in_start, int in_len, int in_step,
                       MyImage &output_img, int out_start, int out_len, int out_step,
                       const Filter &filter);

    void filter_inv_cutoff(MyImage &input_img, int in_start, int in_len, int in_step,
                           MyImage &output_img, int out_start, int out_len, int out_step,
                           const Filter &filter);

    void filter_periodical(MyImage &input_img, int in_start, int in_len, int in_step,
                           MyImage &output_img, int out_start, int out_len, int out_step,
                           const Filter &filter);

    void filter_inv_periodical(MyImage &input_img, int in_start, int in_len, int in_step,
                               MyImage &output_img, int out_start, int out_len, int out_step,
                               const Filter &filter);
    void filter_mirror(MyImage &input_img, int in_start, int in_len, int in_step,
                       MyImage &output_img, int out_start, int out_len, int out_step,
                       const Filter &filter);

    void filter_inv_mirror(MyImage &input_img, int in_start, int in_len, int in_step,
                           MyImage &output_img, int out_start, int out_len, int out_step,
                           const Filter &filter);

    /* copy img2 into img1 at position (x,y)*/
    void copy_into_image(MyImage &img1, const MyImage &img2, int x, int y);
};


#endif //WATERMARKENGINE_DWTUTIL_H
