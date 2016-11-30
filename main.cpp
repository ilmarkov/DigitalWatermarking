#include <iostream>
#include "Facade.h"
//#include "lib/CImg.h"

//using namespace cimg_library;

//typedef double pixel_type;

int main() {
      Facade f;
      f.run();

//    CImg<double> img("ref_image.jpg");
//
//    pixel_type* luminance = NULL; //pointer to pixel size col*rows*depth, depth = 1
//
//    int imgType = 0;
//    int cols = img._width ;
//    int rows = img._height;
//
//    luminance = img.RGBtoYUV().data(0,0,0,0);
//
//    for (int j = 100; j < 110; ++j) {
//        for (int i = 100; i < 110; ++i) {
//            std::cout << (int) (luminance[j*cols + i] * 254) << " ";
//        }
//        std::cout << std::endl;
//    }
//


    return 0;
}