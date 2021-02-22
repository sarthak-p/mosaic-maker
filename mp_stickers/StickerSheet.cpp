#include "StickerSheet.h"
#include "Image.h"
#include <iostream>

using namespace std; 


//constructor, destructor, and helper copy function 

StickerSheet::StickerSheet(const Image & picture, unsigned max) {
    max_ = max; 
    Image picture_ = picture; 
    //creating an array of pointers with size max
    array = new Image *[max_];
    //each image has an index and x,y coordinates 
    x_ = new unsigned[max];
    y_ = new unsigned[max];
    for(unsigned i = 0; i < max; i++) {
        array[i] = nullptr; 
    }
}

StickerSheet::~StickerSheet() {
    for (unsigned i = 0; i < max_; i++) {
        delete array[i];
        array[i] = nullptr; 
    }

    delete[] array; 
    array = nullptr; 
    delete[] x_;
    x_ = nullptr;  
    delete[] y_; 
    y_ = nullptr;
    delete[] new_array; 
    new_array = nullptr;  
}


StickerSheet::StickerSheet(const StickerSheet & other) {
    _copy(other);
}

const StickerSheet & StickerSheet::operator=(const StickerSheet & other) {
    if (this != &other) { 
        _copy(other); 
    }
    return *this;
}


void StickerSheet::_copy(const StickerSheet & other) {
    max_ = other.max_; 
    picture_ = other.picture_; 
    new_array = new Image * [max_];
    x_ = new unsigned[max_];
    y_ = new unsigned[max_];
    for (unsigned i = 0; i < max_; i++) {
        if (array[i] != nullptr) {
            new_array[i] = array[i]; 
        } else {
            new_array[i] = nullptr;
        }
    }
    for (unsigned i = 0; i < sizeof(x_); i++) {
        x_[i] = other.x_[i];
    }
    for (unsigned i = 0; i < sizeof(y_); i++) {
        y_[i] = other.y_[i];
    }
}


//member function documentation 
int StickerSheet::addSticker(Image & sticker, unsigned x, unsigned y) {
    for (unsigned i = 0; i < max_; i++) {
        if (array[i] == nullptr) {
        array[i] = new Image(sticker); 
        x_[i] = x; 
        y_[i] = y; 
        return i;  
        }
    }

    return -1;
}

void StickerSheet::changeMaxStickers(unsigned max) {
    
    //create a new arrays with size max 
    new_array = new Image * [max];
    new_x = new unsigned[max];
    new_y = new unsigned[max];

    //if given max is equal to our max then do nothing
    if (max == max_) {
        return;
    }

    //copy elements including coordinates from our arrays to new arrays
    if (max > max_) {
        for (unsigned i = 0; i < max; i++) {
            if (array[i] != nullptr) {
                new_array[i] = array[i];
                new_x[i] = x_[i];
                new_y[i] = y_[i];
            } else {
                new_array[i] = nullptr; 
            } 
        }
    }

    //if given max is less than our max, then delete those elements 
    if (max < max_) {
        for (unsigned i = max_; i < max; i++) {
            removeSticker(i);
        }
    }

    //we have to set existing arrays equal to new modified arrays 
    array = new_array; 
    x_ = new_x; 
    y_ = new_y; 

    //freeing new arrays to prevent memory leak 
    delete[] new_array; 
    new_array = nullptr; 
    delete[] new_x; 
    new_x = nullptr; 
    delete[] new_y; 
    new_y = nullptr; 
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
        delete array[index];
    //even tho we delete, the space still exists 
        array[index] = nullptr;  
    }
}

Image StickerSheet::render() const {
    Image * base_picture = new Image(); 

    unsigned height_ = picture_.height(); 
    unsigned width_ = picture_.width(); 
    for (unsigned int i = 0; i < max_; i++) {
        if (array[i] != nullptr) {
            unsigned high = (x_[i] + array[i]->width());
            unsigned wide = (y_[i] + array[i]->height());
            
            if (height_ < high) {
                height_ = high; 
            }
            if (width_ < wide) {
                width_ = wide; 
            }
        }
    }

    base_picture->resize(picture_.width(), picture_.height());

    for (unsigned i = 0; i < max_; i++) {
        if (array[i] != nullptr) {
            for(unsigned w = 0; w < picture_.width(); w++) {
                for(unsigned h = 0; h < picture_.height(); h++) {
                    HSLAPixel & base_pixel = base_picture->getPixel(w, h);
                    HSLAPixel & picture_pixel = array[i]->getPixel(w - x_[i], h = y_[i]);
                    if (picture_pixel.a != 0) {
                        base_pixel = picture_pixel; 
                    }
                }
            }
        }
    }
    //have to return Image instead of Image pointer 
    Image image = *base_picture;
    return image; 
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y) {

    for (unsigned i = 0; i < max_; i++) {
        if (i == index && array[i] != nullptr) {
            x_[i] = x; 
            y_[i] = y; 
        }
    }
    return false; 
}









