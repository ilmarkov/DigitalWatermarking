//
// Created by ilya on 07.11.16.
//

#ifndef WATERMARKENGINE_IMAGE_H
#define WATERMARKENGINE_IMAGE_H


#include <assert.h>
#include <new>
#include <iostream>

typedef float Pixel;

class MyImage {
    /**
     * Image data
     * */
    Pixel* data;
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
        }catch (std::bad_alloc e){
            std::cout << e.what() << std::endl;
            exit(-1);
        }
    }

    virtual ~MyImage() {
        delete []data;
    }



    /**
     * Get method for data
     *
     * @return data
     */
    Pixel * getData(){
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
