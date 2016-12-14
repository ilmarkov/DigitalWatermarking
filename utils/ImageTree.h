//
// Created by ilya on 07.11.16.
//

#ifndef WATERMARKENGINE_IMAGETREE_H
#define WATERMARKENGINE_IMAGETREE_H


#include <memory>
#include "MyImage.h"

struct ImageTree{
private:
    double entropy = 0.0;

    std::unique_ptr<ImageTree> coarse;
    std::unique_ptr<ImageTree> horizontal;
    std::unique_ptr<ImageTree> vertical;
    std::unique_ptr<ImageTree> diagonal;
    std::unique_ptr<ImageTree> doubleTree;

    MyImage myImage;

    int level = 0;
    int flag = 0;


public:
    ImageTree():myImage(0,0){}

    double getEntropy() const {
        return entropy;
    }

    void setEntropy(double entropy) {
        ImageTree::entropy = entropy;
    }

    ImageTree(const ImageTree& tree):myImage(tree.myImage){
        if (tree.coarse) {
            coarse.reset(tree.coarse.get());
        } else {
            coarse.reset();
        }
        if (tree.vertical) {
            vertical.reset(tree.vertical.get());
        } else {
            vertical.reset();
        }
        if (tree.horizontal) {
            horizontal.reset(tree.horizontal.get());
        } else {
            horizontal.reset();
        }
        if (tree.diagonal) {
            diagonal.reset(tree.diagonal.get());
        } else {
            diagonal.reset();
        }
        if (tree.doubleTree) {
            doubleTree.reset(tree.doubleTree.get());
        } else {
            doubleTree.reset();
        }
    }

    void setCoarse(const ImageTree &coarse) {
        ImageTree::coarse.reset(new ImageTree(coarse));
    }

    const ImageTree &getCoarse() const {
        return *coarse;
    }

    ImageTree& getCoarse() {
        return *coarse;
    }

    void setVertical(const ImageTree &vertical){
        ImageTree::vertical.reset(new ImageTree(vertical));
    }

    const ImageTree &getVertical() const {
        return *vertical;
    }

    ImageTree &getVertical() {
        return *vertical;
    }

    void setHorizontal(const ImageTree &horizontal){
        ImageTree::horizontal.reset(new ImageTree(horizontal));
    }


    const ImageTree &getHorizontal() const {
        return *horizontal;
    }

    ImageTree &getHorizontal() {
        return *horizontal;
    }

    void setDiagonal(const ImageTree &diagonal){
        ImageTree::diagonal.reset(new ImageTree(diagonal));
    }

    const ImageTree &getDiagonal() const {
        return *diagonal;
    }

    ImageTree &getDiagonal() {
        return *diagonal;
    }

    ImageTree &getDoubleTree() const {
        return *doubleTree;
    }

    void setDoubleTree(const ImageTree &doubleTree) {
        ImageTree::doubleTree.reset(new ImageTree(doubleTree));
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

    MyImage &getImage() {
        return myImage;
    }

    void setImage(MyImage &myImage) {
        ImageTree::myImage = myImage;
    }

    ImageTree& operator=(ImageTree& tree){
        myImage = tree.myImage;
        if (tree.coarse)
            *coarse = *tree.coarse;
        if (tree.vertical)
            *vertical = *tree.vertical;
        if (tree.diagonal)
            *horizontal = *tree.vertical;
        if (tree.diagonal)
            *diagonal = *tree.diagonal;
        if (tree.doubleTree)
            *doubleTree = *tree.doubleTree;
    }
};

#endif //WATERMARKENGINE_IMAGETREE_H
