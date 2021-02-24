#include "StickerSheet.h"
#include "Image.h"
#include <iostream>
#include <algorithm>

using namespace std; 


//constructor 
StickerSheet::StickerSheet(const Image & picture, unsigned max) {
    max_ = max; 
    //copying our picture to an image pointer
    picture_ = picture; 
    //creating an array of pointers with size max
    array = new Image [max_];
    //each image has an index and x,y coordinates 
    x_ = new unsigned[max_];
    y_ = new unsigned[max_];
}

StickerSheet::StickerSheet(const StickerSheet & other) {
    _copy(other);
}

const StickerSheet & StickerSheet::operator=(const StickerSheet & other) {
    if (this != &other) {
        _clear();
        _copy(other);
    }
    return *this;
}


void StickerSheet::_copy(const StickerSheet & other) {
    max_ = other.max_; 
    picture_ = other.picture_; 
    array = new Image [max_];
    x_ = new unsigned[max_];
    y_ = new unsigned[max_];
    for (unsigned i = 0; i < max_; i++) {
        array[i] = other.array[i];
        x_[i] = other.x_[i];
        y_[i] = other.y_[i];
    }
}


void StickerSheet::_clear() {
    //deleting the arrays 
    delete[] array; 
    array = NULL; 
    delete[] x_;
    x_ = NULL; 
    delete[] y_; 
    y_ = NULL; 
}

//destructor 
StickerSheet::~StickerSheet() {
    _clear(); 
}


//member function documentation 
int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y) {   
    for (unsigned i = 0; i < max_; i++) {
        if (array[i] != typeof(Image)) {
        //can only add to spaces that are NULL
            x_[i] = x; 
            y_[i] = y; 
            array[i] = new Image(sticker);
            return i;
        }
    }
    return -1; 
}


void StickerSheet::changeMaxStickers(unsigned max) {

    unsigned number = 0;
    if (max > max_)
    {
        number = max_;
    }
    else if (max < max_)
    {
        number = max;
    }

    //if given max is equal to our max then do nothing
    if (max == max_) {
        return;
    } else {
        Image * new_array = new Image [max];
        unsigned * new_x = new unsigned[max];
        unsigned * new_y = new unsigned[max];

        for (unsigned i = 0; i < number; i++) {
                new_array[i] = new Image(array[i]);
                new_x[i] = x_[i];
                new_y[i] = y_[i];
            }
            _clear();
            array = new_array;
            x_ = new_x;
            y_ = new_y;
            max_ = max;
    }
}

Image * StickerSheet::getSticker(unsigned index) {
    //if index is less than max, then we return the element at the index 
    if (index < max_) {
        return array[index];
    //if not return NULL
    } else {
        return NULL; 
    }
}

void StickerSheet::removeSticker (unsigned index) {
    for (unsigned i = 0; i < max_; i++) {
        if ((index < max_) && (array[index] != nullptr)) {
            delete array[index];
            array[index] = nullptr;
        }
    }
}


Image StickerSheet::render() const {
    
    Image base = picture_;  
    unsigned height_ = picture_.height(); 
    unsigned width_ = picture_.width(); 
    unsigned highest; 
    unsigned widest; 

    //checking if each sticker is out of bounds 
    for (unsigned i = 0; i < max_; i++) {
        
        if (array[i] != nullptr) {
            highest = (y_[i] + array[i]->height());
            widest = (x_[i] + array[i]->width());
        }
        if (height_ < highest) {
            height_ = highest; 
        }
        if (width_ < widest) {
            width_ = widest; 
        }
    }

    base.resize(width_, height_);

    for (unsigned i = 0; i < max_; i++) {
        if (_.i) {
            for(unsigned w = x_[i]; w < (array[i].width() + x_[i]); w++) {
                for(unsigned h = y_[i]; h < (array[i].height() + y_[i]); h++) {
                    HSLAPixel & pixel = base.getPixel(w, h);
                    HSLAPixel & picture_pixel = array[i].getPixel(w - x_[i], h - y_[i]);
                    if (picture_pixel.a != 0) {
                        pixel = picture_pixel; 
                    }
                }
            }
        }
    }
    return base; 
}



bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {

    for (unsigned i = 0; i < max_; i++) {
        if ((i == index) && (array[i] != nullptr)) {
            x_[i] = x; 
            y_[i] = y; 
            return true; 
        }
    }
    return false; 
}
