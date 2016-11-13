//
// Created by ilya on 07.11.16.
//

#ifndef WATERMARKENGINE_IMAGETREE_H
#define WATERMARKENGINE_IMAGETREE_H


#include "MyImage.h"

struct ImageTree{
private:
    double entropy = 0.0;

    ImageTree* coarse;
    ImageTree* horizontal;
    ImageTree* vertical;
    ImageTree* diagonal;
    ImageTree* doubleTree;

    MyImage* image;

    int level = 0;
    int flag = 0;

public:
    double getEntropy() const {
        return entropy;
    }

    void setEntropy(double entropy) {
        ImageTree::entropy = entropy;
    }

    ImageTree *getCoarse() const {
        return coarse;
    }

    void setCoarse(ImageTree *coarse) {
        ImageTree::coarse = coarse;
    }

    ImageTree *getHorizontal() const {
        return horizontal;
    }

    void setHorizontal(ImageTree *horizontal) {
        ImageTree::horizontal = horizontal;
    }

    ImageTree *getVertical() const {
        return vertical;
    }

    void setVertical(ImageTree *vertical) {
        ImageTree::vertical = vertical;
    }

    ImageTree *getDiagonal() const {
        return diagonal;
    }

    void setDiagonal(ImageTree *diagonal) {
        ImageTree::diagonal = diagonal;
    }

    ImageTree *getDoubleTree() const {
        return doubleTree;
    }

    void setDoubleTree(ImageTree *doubleTree) {
        ImageTree::doubleTree = doubleTree;
    }

    MyImage *getImage() const {
        return image;
    }

    void setImage(MyImage *image) {
        ImageTree::image = image;
    }

    int getLevel() const {
        return level;
    }

    void setLevel(int level) {
        ImageTree::level = level;
    }

    int getFlag() const {
        return flag;
    }

    void setFlag(int flag) {
        ImageTree::flag = flag;
    }
};

#endif //WATERMARKENGINE_IMAGETREE_H
