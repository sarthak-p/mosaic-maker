/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */

#pragma once
#include "Image.h"

using namespace cs225; 

class StickerSheet {
    public:
    StickerSheet(const Image & picture, unsigned max);
    int addSticker(Image & sticker, unsigned x, unsigned y);
    Image render() const; 
    ~StickerSheet(); 
    StickerSheet(const StickerSheet & other);
    const StickerSheet & operator=(const StickerSheet & other);
    void changeMaxStickers(unsigned max);
    bool translate(unsigned index, unsigned x, unsigned y);
    void removeSticker(unsigned index);
    Image * getSticker(unsigned index);

    private:
    Image picture_; 
    Image ** array; 
    Image ** new_array; 
    unsigned max_; 
    unsigned * x_; 
    unsigned * y_;
    unsigned * new_x; 
    unsigned * new_y;  
    void _copy(const StickerSheet & other); 
};
 
