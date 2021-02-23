/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */

#pragma once
#include "Image.h"
#include <vector>


using namespace std; 
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
    void _copy(const StickerSheet & other); 
    void _clear();


    private:
    Image picture_; 
    Image ** array; 
    unsigned max_; 
    unsigned * x_; 
    unsigned * y_;  
};
 
