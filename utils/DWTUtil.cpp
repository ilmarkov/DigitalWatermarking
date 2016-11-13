//
// Created by ilya on 07.11.16.
//

#include "DWTUtil.h"

//util functions

void DWTUtil::copy_into_image(MyImage* img1,MyImage* img2,int x,int y)
{
    int start,i,j,aim;
    Pixel *temp;
    temp=img2->getData();
    start=img1->getWidth()*y+x;
    for (i=0;i<img2->getHeight();i++) {
        for (j=0;j<img2->getWidth();j++) {
            aim=start+j+img1->getWidth()*i;
            img1->getData()[aim] = *temp;
            temp++;
        }
    }
}

ImageTree* DWTUtil::waveletTransform(MyImage* origImg, int level, FilterGH *filterGHList, int method) {
    int i,width,height,min,max_level,e;
    MyImage* coarseImg;
    MyImage* horizontalImg;
    MyImage* verticalImg;
    MyImage* diagonalImg;
    MyImage* tempImg;
    ImageTree* returnTree, *tempTree;

    width = origImg->getWidth();
    height = origImg->getHeight();

    tempImg = new MyImage(width, height);
    if(!tempImg)
        throw std::exception();

    copy_into_image(tempImg,origImg,0,0);

    returnTree = new ImageTree();
    if(!returnTree)
        throw std::exception();

    tempTree = returnTree;
    returnTree->setLevel(0);

    min = origImg->getWidth();
    if (origImg->getHeight() < min)
        min=origImg->getHeight();

    max_level = log(min)/log(2)-2;

    if (max_level < level)
        level = max_level;

    if (level < 1)  /* do not transform */
    {
        returnTree->setImage(tempImg);
        return returnTree;
    }

    /* decomposition */

    for (i = 0;i < level;i++)
    {

        width=(width+1)/2;
        height=(height+1)/2;

        coarseImg = new MyImage(width,height);
        horizontalImg = new MyImage(width,height);
        verticalImg = new MyImage(width,height);
        diagonalImg = new MyImage(width,height);
        if(!coarseImg||!horizontalImg||!verticalImg||!diagonalImg)
            throw std::exception();

        decomposition(tempImg,coarseImg,horizontalImg,verticalImg,diagonalImg,
                          filterGHList[i].getG(),filterGHList[i].getH(),method);
        if (!e) return NULL;

        tempTree->setCoarse(new ImageTree());
        tempTree->setHorizontal(new ImageTree());
        tempTree->setVertical(new ImageTree());
        tempTree->setDiagonal(new ImageTree());

        tempTree->getCoarse()->setLevel(i + 1);
        tempTree->getHorizontal()->setLevel(i + 1);
        tempTree->getVertical()->setLevel(i + 1);
        tempTree->getDiagonal()->setLevel(i + 1);

        tempTree->getHorizontal()->setImage(horizontalImg);
        tempTree->getVertical()->setImage(verticalImg);
        tempTree->getDiagonal()->setImage(diagonalImg);
        delete tempImg;

        if (i!=(level-1))
        {
            tempImg=new MyImage(width,height);
            copy_into_image(tempImg,coarseImg,0,0);
            delete coarseImg;
            /*if i=level coarseImg is inserted into the image tree
              so we should not free coarseImg on level-1*/
        }

        tempTree=tempTree->getCoarse();

    }

    tempTree->setImage(coarseImg);
    return returnTree;
}

ImageTree* DWTUtil::waveletTransformWp(MyImage* origImg, int current_level, int level, FilterGH *filterGHList,
                                       int method) {
    int i, width, height, min, max_level, e;
    MyImage *coarse_image, *horizontal_image, *vertical_image, *diagonal_image, *temp_image;
    ImageTree *returnTree, *tempTree;

    width = origImg->getWidth();
    height = origImg->getHeight();

    temp_image = new MyImage(width, height);

    copy_into_image(temp_image, origImg, 0, 0);

    returnTree = new ImageTree();
    tempTree = returnTree;
    tempTree->setLevel(current_level);

    min = origImg->getWidth();
    if (origImg->getHeight() < min)
        min = origImg->getHeight();

    max_level = log(min) / log(2) - 2;

    if (max_level < level)
        level = max_level;

    if (current_level >= level) {
        returnTree->setImage(temp_image);
        return returnTree;
    }

    for (i = current_level; i < level; i++) {
        width = (width + 1) / 2;
        height = (height + 1) / 2;

        coarse_image = new MyImage(width, height);
        horizontal_image = new MyImage(width, height);
        vertical_image = new MyImage(width, height);
        diagonal_image = new MyImage(width, height);


        decomposition(temp_image, coarse_image, horizontal_image,
                          vertical_image, diagonal_image,
                          filterGHList[i].getG(), filterGHList[i].getH(), method);

        tempTree->setCoarse(new ImageTree());
        tempTree->getCoarse()->setLevel(i + 1);
        tempTree->setHorizontal(waveletTransformWp(horizontal_image, i + 1, level, filterGHList, method));
        tempTree->setVertical(waveletTransformWp(vertical_image, i + 1, level, filterGHList, method));
        tempTree->setDiagonal(waveletTransformWp(diagonal_image, i + 1, level, filterGHList, method));

        delete horizontal_image;
        delete vertical_image;
        delete diagonal_image;
        delete temp_image;

        if (i != (level - 1)) {
            temp_image = new MyImage(width, height);
            copy_into_image(temp_image, coarse_image, 0, 0);
            delete coarse_image;
        }

        tempTree = tempTree->getCoarse();
    }

    tempTree->setImage(coarse_image);
    return returnTree;
}


MyImage* DWTUtil::inv_transform(ImageTree* tree, FilterGH *flt, enum FilterMethod method) {
    int er, width, height;
    MyImage *ret_img, *coarse, *vertical, *horizontal, *diagonal;

    if (!tree->getImage()) {

        coarse = inv_transform(tree->getCoarse(), flt, method);
        horizontal = inv_transform(tree->getHorizontal(), flt, method);
        vertical = inv_transform(tree->getHorizontal(), flt, method);
        diagonal = inv_transform(tree->getDiagonal(), flt, method);
        if (!coarse || !horizontal || !vertical || !diagonal)
            return NULL;

        width = coarse->getWidth() + horizontal->getWidth();
        height = coarse->getHeight() + vertical->getHeight();

        ret_img = new MyImage(width, height);

        if (tree->getFlag() == 0)        /*if flag is set it is a doubletree tiling*/
        {
//			er=inv_decomposition(ret_img,coarse,horizontal,vertical,diagonal,flt[1],method);
            inv_decomposition(ret_img, coarse, horizontal, vertical, diagonal, flt[tree->getLevel()], method);
        } else {
            copy_into_image(ret_img, coarse, 0, 0);
            copy_into_image(ret_img, horizontal, coarse->getWidth(), 0);
            copy_into_image(ret_img, vertical, 0, coarse->getHeight());
            copy_into_image(ret_img, diagonal, coarse->getWidth(), coarse->getHeight());
        }

        if (!tree->getCoarse()->getImage()) delete coarse;
        if (!tree->getHorizontal()->getImage()) delete horizontal;
        if (!tree->getVertical()->getImage()) delete vertical;
        if (!tree->getDiagonal()->getImage()) delete diagonal;

        return ret_img;
    } else
        return tree->getImage();
}

void DWTUtil::decomposition(MyImage *inputImg, MyImage *coarse_img, MyImage *horizontalImg, MyImage *verticalImg,
                           MyImage *diagonalImg, Filter filterG, Filter filterH, int method) {

    MyImage* tempImg = new MyImage(coarse_img->getWidth(),inputImg->getHeight());

    /*coarse*/
    convolute_lines(tempImg,inputImg,filterH,method);
    convolute_rows(coarse_img, tempImg, filterH, method);

    /*horizontal*/
    convolute_rows(horizontalImg, tempImg, filterG, method);
    delete tempImg;

    /*vertical*/
    tempImg = new MyImage(verticalImg->getWidth(),inputImg->getHeight());

    convolute_lines(tempImg,inputImg,filterG,method);
    convolute_rows(verticalImg, tempImg, filterH, method);

    /*diagonal*/
    convolute_rows(diagonalImg, tempImg, filterG, method);
    delete tempImg;



}


void DWTUtil::inv_decomposition(MyImage* sum_img, MyImage* coarse_img, MyImage* horizontal_img, MyImage* vertical_img,
                           MyImage* diagonal_img, FilterGH filter_GH, int method){



    MyImage* temp1;
    Filter g,h;

    if (filter_GH.getType()==FTOrtho) {
        g=filter_GH.getG();
        h=filter_GH.getH();
    }
    else {
        g=filter_GH.getGi();
        h=filter_GH.getHi();
    }

    /*coarse*/
    temp1 = new MyImage(coarse_img->getWidth(), sum_img->getHeight());
    convolute_rows(temp1,coarse_img,h,method);

    /*horizontal*/
    convolute_rows(temp1,horizontal_img,g,method);
    convolute_lines(sum_img,temp1,h,method);
    delete temp1;

    /*vertical*/
    temp1 = new MyImage(vertical_img->getWidth(),sum_img->getHeight());

    convolute_rows(temp1,vertical_img,h,method);

    /*diagonal*/
    convolute_rows(temp1,diagonal_img,g,method);
    convolute_lines(sum_img,temp1,g,method);

    delete temp1;

}

void DWTUtil::convolute_lines(MyImage* outputImg, MyImage* inputImg, Filter filter, int method){
    using namespace DWTUtil;

    for (int i = 0;i < inputImg->getHeight(); i++) {
        switch(method) {
            case cutoff:
                filter_cutoff(inputImg,inputImg->getWidth()*i,inputImg->getWidth(),1,
                              outputImg,outputImg->getWidth()*i,outputImg->getWidth(),1,filter);
                break;
            case inv_cutoff:
                filter_inv_cutoff(inputImg,inputImg->getWidth()*i,inputImg->getWidth(),1,
                                  outputImg,outputImg->getWidth()*i,outputImg->getWidth(),1,filter);
                break;
            case periodical:
                filter_periodical(inputImg,inputImg->getWidth()*i,inputImg->getWidth(),1,
                                  outputImg,outputImg->getWidth()*i,outputImg->getWidth(),1,filter);
                break;
            case inv_periodical:
                filter_inv_periodical(inputImg,inputImg->getWidth()*i,inputImg->getWidth(),1,
                                      outputImg,outputImg->getWidth()*i,outputImg->getWidth(),1,filter);
                break;
            case mirror:
                filter_mirror(inputImg,inputImg->getWidth()*i,inputImg->getWidth(),1,
                              outputImg,outputImg->getWidth()*i,outputImg->getWidth(),1,filter);
                break;
            case inv_mirror:
                filter_inv_mirror(inputImg,inputImg->getWidth()*i,inputImg->getWidth(),1,
                                  outputImg,outputImg->getWidth()*i,outputImg->getWidth(),1,filter);
                break;


        }
    }

}

void DWTUtil::convolute_rows(MyImage* outputImg, MyImage* inputImg, Filter filter, int method){
    for (int i = 0;i < inputImg->getWidth();i++)
    {
        switch (method)
        {
            case cutoff:
                filter_cutoff(inputImg,i,inputImg->getHeight(),inputImg->getWidth(),
                              outputImg,i,outputImg->getHeight(),outputImg->getWidth(),filter);
                break;
            case inv_cutoff:
                filter_inv_cutoff(inputImg,i,inputImg->getHeight(),inputImg->getWidth(),
                                  outputImg,i,outputImg->getHeight(),outputImg->getWidth(),filter);
                break;
            case periodical:
                filter_periodical(inputImg,i,inputImg->getHeight(),inputImg->getWidth(),
                                  outputImg,i,outputImg->getHeight(),outputImg->getWidth(),filter);
                break;
            case inv_periodical:
                filter_inv_periodical(inputImg,i,inputImg->getHeight(),inputImg->getWidth(),
                                      outputImg,i,outputImg->getHeight(),outputImg->getWidth(),filter);
                break;
            case mirror:
                filter_mirror(inputImg,i,inputImg->getHeight(),inputImg->getWidth(),
                              outputImg,i,outputImg->getHeight(),outputImg->getWidth(),filter);
                break;
            case inv_mirror:
                filter_inv_mirror(inputImg,i,inputImg->getHeight(),inputImg->getWidth(),
                                  outputImg,i,outputImg->getHeight(),outputImg->getWidth(),filter);
                break;

        }
    }
}


#define FLOOR_HALF(x) ((x)&1 ? ((x)-1)/2 : (x)/2)
#define CEILING_HALF(x) ((x)&1 ? ((x)+1)/2 : (x)/2)
#define MOD(a,b) ( (a)<0 ? ((b)-((-(a))%(b))) : (a)%(b) )

void DWTUtil::filter_cutoff(MyImage* input_img, int in_start, int in_len, int in_step, MyImage* output_img, int out_start,
                        int out_len, int out_step, Filter filter){

    int fStart = 0;
    int fEnd = 0;

    for(int i = 0; i < out_len; i++)
    {
        fStart = std::max((2 * i) - (in_len - 1), filter.getStart());
        fEnd = std::min((2 * i), filter.getEnd());

        for(int j = fStart; j <= fEnd; j++)
        {
            output_img->getData()[out_start + i * out_step] += filter.getData()[j - filter.getStart()]
                                                           * input_img->getData()[in_start + ((2 * i) - j) * in_step];
        }
    }

}

void DWTUtil::filter_inv_cutoff(MyImage *input_img, int in_start, int in_len, int in_step, MyImage *output_img,
                               int out_start, int out_len, int out_step, Filter filter) {
    int fStart = 0;
    int fEnd = 0;

    for(int i = 0; i < out_len; i++)
    {
        fStart = std::max(CEILING_HALF(filter.getStart() + i), 0);
        fEnd = std::min(FLOOR_HALF(filter.getEnd()), in_len - 1);

        for(int j = fStart; j <= fEnd; j++)
        {
            output_img->getData()[out_start+ i * out_step] += filter.getData()[(2 * j) - i - filter.getStart()]
                                                           * input_img->getData()[in_start + j * in_step];
        }
    }
}

void DWTUtil::filter_periodical(MyImage *input_img, int in_start, int in_len, int in_step, MyImage* output_img,
                               int out_start, int out_len, int out_step, Filter filter) {
    int fStart = 0;
    int fEnd = 0;
    int iStart = 0;

    for(int i = 0; i < out_len; i++)
    {
        fStart = filter.getStart();
        fEnd = filter.getEnd();
        iStart = MOD(((2 * i) - fStart), in_len);

        for(int j = fStart; j <= fEnd; j++)
        {
            output_img->getData()[out_start + i * out_step] += filter.getData()[j - fStart]
                                                           * input_img->getData()[in_start + iStart * in_step];
            iStart--;
            if(iStart < 0)
            {
                iStart += in_len;
            }
        }
    }
}

void DWTUtil::filter_inv_periodical(MyImage *input_img, int in_start, int in_len, int in_step, MyImage *output_img,
                                    int out_start, int out_len, int out_step, Filter filter) {
    int fStart = 0;
    int fEnd = 0;
    int iStart = 0;

    for(int i = 0; i < out_len; i++)
    {
        fStart = CEILING_HALF(filter.getStart()+i);
        fEnd=FLOOR_HALF(filter.getEnd()+i);

        iStart =MOD(fStart, in_len);

        for(int j = fStart; j <= fEnd; j++)
        {
            output_img->getData()[out_start + i * out_step] += filter.getData()[(2 * j) - i - filter.getStart()]
                                                           * input_img->getData()[in_start + iStart * in_step];
            iStart++;
            if(iStart >= in_len)
            {
                iStart -= in_len;
            }
        }
    }
}


void DWTUtil::filter_mirror(MyImage *input_img, int in_start, int in_len, int in_step, MyImage *output_img, int out_start,
                            int out_len, int out_step, Filter filter) {
    int fStart = 0;
    int fEnd = 0;
    int in_pos = 0;

    for(int i = 0; i < out_len; i++)
    {
        fStart = filter.getStart();
        fEnd = filter.getEnd();

        for(int j = fStart; j <= fEnd; j++)
        {
            in_pos = ((2 * i) - j);
            if(in_pos < 0)
            {
                in_pos = -in_pos;
                if(in_pos >= in_len)
                {
                    continue;
                }
            }
            if(in_pos >= in_len)
            {
                in_pos = 2 * in_len - 2 - in_pos;
                if(in_pos < 0)
                {
                    continue;
                }
            }
            output_img->getData()[out_start + i * out_step] += filter.getData()[j - fStart]
                                                           * input_img->getData()[in_start + in_pos * in_step];
        }
    }
}

void DWTUtil::filter_inv_mirror(MyImage *input_img, int in_start, int in_len, int in_step, MyImage *output_img,
                                int out_start, int out_len, int out_step, Filter filter) {

    int fStart = 0;
    int fEnd = 0;
    int in_pos = 0;

    for(int i = 0; i < out_len; i++)
    {
        fStart = CEILING_HALF(filter.getStart() + i);
        fEnd = FLOOR_HALF(filter.getEnd() + i);

        for(int j = fStart; j <= fEnd; j++)
        {
            in_pos = j;
            if(in_pos < 0)
            {
                if(filter.getHipass())
                {
                    in_pos = -in_pos - 1;
                }
                else
                {
                    in_pos = -in_pos;
                }
                if(in_pos >= in_len)
                {
                    continue;
                }
            }
            if(in_pos >= in_len)
            {
                if(filter.getHipass())
                {
                    in_pos = 2 * in_len - 2 - in_pos;
                }
                else
                {
                    in_pos = 2 * in_len - 1 - in_pos;
                }
                if(in_pos < 0)
                {
                    continue;
                }
            }
            output_img->getData()[out_start + i * out_step] += filter.getData()[2 * j - i - filter.getStart()]
                                                           * input_img->getData()[in_start + in_pos * in_step];
        }
    }
}


int DWTUtil::find_deepest_level(int width, int height) {
    int level=0,w=width,h=height;

    while ( !((w%2)||(h%2)))
    {
        w=w/2;
        h=h/2;
        level++;
    }

    return level-1;
}

Pixel *DWTUtil::Filter::getData() const {
    return data;
}

int DWTUtil::Filter::getStart() const {
    return start;
}

int DWTUtil::Filter::getEnd() const {
    return end;
}

int DWTUtil::Filter::getHipass() const {
    return hipass;
}

void DWTUtil::Filter::setHipass(int hipass) {
    Filter::hipass = hipass;
}

void DWTUtil::Filter::setStart(int start) {
    Filter::start = start;
}

void DWTUtil::Filter::setEnd(int end) {
    Filter::end = end;
}

void DWTUtil::Filter::setType(std::string type_str) {
    if(type_str == "nosymm")
    {
        type = DWTUtil::FTNoSymm;
    }
    else if(type_str == "symm")
    {
        type = DWTUtil::FTSymm;
    }
    else if(type_str == "antisymm")
    {
        type = DWTUtil::FTAntiSymm;
    }
    else
    {
        throw ProjectException("no such type for Filter");
    }
}

void DWTUtil::Filter::setData(std::vector<Pixel> vector) {
    data = new Pixel[vector.size()];
    for (int i = 0; i < vector.size(); ++i) {
        data[i] = vector[i];
    }
}

void DWTUtil::FilterGH::setType(std::string type_str) {
    if (type_str == "orthogonal")
    {
        type = DWTUtil::FTOrtho;
    }
    else if (type_str == "biorthogonal")
    {
        type = DWTUtil::FTBiOrtho;
    }
    else if (type_str == "other")
    {
        type = DWTUtil::FTOther;
    }
    else
    {
        throw ProjectException("no such type for FilterGH");
    }
}

DWTUtil::Filter DWTUtil::FilterGH::getG() const {
    return g;
}

void DWTUtil::FilterGH::setG(DWTUtil::Filter g) {
    FilterGH::g = g;
}

DWTUtil::Filter DWTUtil::FilterGH::getH() const {
    return h;
}

void DWTUtil::FilterGH::setH( DWTUtil::Filter h) {
    FilterGH::h = h;
}

DWTUtil::Filter DWTUtil::FilterGH::getGi() const {
    return gi;
}

void DWTUtil::FilterGH::setGi(DWTUtil::Filter gi) {
    FilterGH::gi = gi;
}

DWTUtil::Filter DWTUtil::FilterGH::getHi() const {
    return hi;
}

void DWTUtil::FilterGH::setHi(DWTUtil::Filter hi) {
    FilterGH::hi = hi;
}

int DWTUtil::FilterGH::getId() const {
    return id;
}

void DWTUtil::FilterGH::setId(int id) {
    FilterGH::id = id;
}

void DWTUtil::FilterGH::setName(char *name) {
    FilterGH::name = name;
}

DWTUtil::FilterGHType DWTUtil::FilterGH::getType() const {
    return type;
}
