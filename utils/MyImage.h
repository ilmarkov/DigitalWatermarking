//
// Created by ilya on 07.11.16.
//

#ifndef WATERMARKENGINE_IMAGE_H
#define WATERMARKENGINE_IMAGE_H


#include <assert.h>
#include <new>
#include <iostream>
#include <cstring>
#include <math.h>

typedef float Pixel;

class MyImage {
    /**
     * Image data
     * */
    Pixel* data = NULL;
    /**
     * Image width
     * */
    int width  = 0;
    /**
     * Image height
     * */
    int height = 0;


public:

    /**
     * Default constructor
     *
     * @param width Width of the image
     * @param height Height of the image
     * */
    MyImage(int width_, int height_):width(width_), height(height_){
        try {
            data = new Pixel[width * height];
            std::fill_n(data, width_*height_, 0.0);
        }catch (std::bad_alloc e){
            std::cout << e.what() << std::endl;
            exit(-1);
        }
    }

    void print(){
        for (int i = 0; i < 10; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl << std::endl;

    }

    virtual ~MyImage() {
        width = 0;
        height = 0;
        delete []data;
    }
    //TODO: ask how to use const here
    MyImage(const MyImage& that){
        width = that.getWidth();
        height = that.getHeight();
        if (data)
            delete[] data;
        data = new Pixel[width*height];
        memcpy(data, that.getData(), width*height*sizeof(Pixel));
    }

    MyImage& operator=(const MyImage& that){
        width = that.getWidth();
        height = that.getHeight();
        if (data)
            delete[] data;
        data = new Pixel[width*height];
        memcpy(data, that.getData(), width*height*sizeof(Pixel));
        return *this;
    }

    /**
     * Get method for data
     *
     * @return data
     */
    Pixel * getData(){
        return data;
    }
    const Pixel * getData() const{
        return data;
    }

    /**
     * Set method for data
     *
     * @param data
     */
    void setData(Pixel *data) {
        MyImage::data = data;
    }

    /**
     * Get method for width
     *
     * @return width
     */
    int getWidth() const {
        return width;
    }

    /**
     * Set method for width
     *
     * @param width
     */
    void setWidth(int width) {
        MyImage::width = width;
    }

    /**
     * Get method for height
     *
     * @return height
     */
    int getHeight() const {
        return height;
    }


    /**
     * Operator equality
     * @param image
     * */
    bool operator==(const MyImage& image){
        if (width != image.width || height != image.height)
            return false;
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (fabs(data[i * height + j] - image.data[i * height + j]) > 1E-6)
                    return false;
            }
        }
        return true;
    }

    /**
     * Operator inequality
     * @param image
     * */

    bool operator!=(const MyImage& image){
        return !((*this)==image);
    }


     /**
     * Set method for height
     *
     * @param height
     */
    void setHeight(int height) {
        MyImage::height = height;
    }

    Pixel getPixel(int x, int y){
        if( x < 0 || x >= width || y < 0 || y >= width)
        {
            return 0.0;
        }
        else
        {
            return data[x + y * width];
        }
    }

    void setPixel(int x, int y, Pixel val){
        if(!(x < 0 || x >= width || y < 0 || y >= height))
        {
            data[x + (y * width)] = val;
        }
    }
};


#endif //WATERMARKENGINE_IMAGE_H
