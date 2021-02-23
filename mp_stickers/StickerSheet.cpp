#include "StickerSheet.h"
#include "Image.h"
#include <iostream>

using namespace std; 


//constructor 
StickerSheet::StickerSheet(const Image & picture, unsigned max) {
    max_ = max; 
    //copying our picture to an image pointer
    picture_ = picture; 
    //creating an array of pointers with size max
    array = new Image * [max_];
    //each image has an index and x,y coordinates 
    x_ = new unsigned[max_];
    y_ = new unsigned[max_];
    //each ele in array should me assigned nullptr manually
    for(unsigned i = 0; i < max_; i++) {
        array[i] = nullptr; 
    }
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
    array = new Image * [max_];
    x_ = new unsigned[max_];
    y_ = new unsigned[max_];
    for (unsigned i = 0; i < max_; i++) {
        if (other.array[i] != nullptr) {
            array[i] = other.array[i];
            x_[i] = other.x_[i]; 
            y_[i] = other.y_[i]; 
        }
    }
}

void StickerSheet::_clear() {
    //freeing each element in the array 
    for (unsigned i = 0; i < max_; i++) {
        if (array[i] != nullptr) {
            delete array[i];
            array[i] = nullptr;
        }
    }

    //deleting the arrays 
    delete[] array; 
    array = nullptr; 
    delete[] x_;
    x_ = nullptr; 
    delete[] y_; 
    y_ = nullptr; 

}

//destructor 
StickerSheet::~StickerSheet() {
    _clear(); 
}


//member function documentation 
int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y) { 
    Image * point = &sticker; 
    for (unsigned i = 0; i < max_; i++) {
        //can only add to spaces that are nullptr
        if (array[i] == nullptr) {
            x_[i] = x; 
            y_[i] = y; 
            array[i] = point;  
            return i;  
        }
    }
    return -1;
}


void StickerSheet::changeMaxStickers(unsigned max) {

    Image ** new_array = new Image * [max];
    unsigned * new_x = new unsigned[max];
    unsigned * new_y = new unsigned[max];

    //if given max is equal to our max then do nothing
    if (max == max_) {
        return;
    }

    //adding all elements to the array
    for (unsigned i = 0; i < max_; i++) {
        if (array[i] != nullptr) {
            new_array[i] = array[i];
            new_x[i] = x_[i];
            new_y[i] = y_[i];
        }
    }

    if (max < max_) {
        for (unsigned i = max; i < max_; i++) {
            delete array[i];
            array[i] = nullptr; 
        }
    }

    _clear(); 
    array = new_array; 
    x_ = new_x; 
    y_ = new_y; 
    max_ = max; 
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
        if (array[i] != nullptr) {
            for(unsigned w = x_[i]; w < (array[i]->width() + x_[i]); w++) {
                for(unsigned h = y_[i]; h < (array[i]->height() + y_[i]); h++) {
                    HSLAPixel & pixel = base.getPixel(w, h);
                    HSLAPixel & picture_pixel = array[i]->getPixel(w - x_[i], h - y_[i]);
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









