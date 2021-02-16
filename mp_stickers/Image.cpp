#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace cs225; 

void Image::lighten() {
    for (unsigned x = 0; x < width(); x++)
    {
        for (unsigned y = 0; y < height(); y++)
        {
            HSLAPixel & current = getPixel(x, y);
            current.l += 0.1; 
            if (current.l > 1.0)
            {
                current.l = 1.0;
            }

            if (current.l < 0.0)
            {
                current.l = 0.0;
            }
        }
    }
}


void Image::lighten(double amount) {
    for (unsigned x = 0; x < width(); x++)
    {
        for (unsigned y = 0; y < height(); y++)
        {
            HSLAPixel &current = getPixel(x, y);
            current.l += amount;
            if (current.l > 1.0)
            {
                current.l = 1.0;
            }

            if (current.l < 0.0)
            {
                current.l = 0.0;
            }
        }
    }
}

void Image::darken() {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            current.l -= 0.1; 
            if (current.l > 1.0) {
                current.l = 1.0;
            }
            if (current.l < 0.0) {
                current.l = 0.0;
            }
        }
    }
}

void Image::darken(double amount) {
    for (unsigned x = 0; x < width(); x++)
    {
        for (unsigned y = 0; y < height(); y++)
        {
            HSLAPixel & current = getPixel(x, y);
            current.l -= amount;
            if (current.l > 1.0)
            {
                current.l = 1.0;
            }
            if (current.l < 0.0)
            {
                current.l = 0.0;
            }
        }
    }
}

void Image::saturate() {

    for (unsigned x = 0; x < width(); x++)
    {
        for (unsigned y = 0; y < height(); y++)
        {
            HSLAPixel &current = getPixel(x, y);
            current.s += 0.1;
            if (current.s > 1.0)
            {
                current.s = 1.0;
            }
            if (current.s < 0.0)
            {
                current.s = 0.0;
            }
        }
    }
}

void Image::saturate(double amount) {

    for (unsigned x = 0; x < width(); x++)
    {
        for (unsigned y = 0; y < height(); y++)
        {
            HSLAPixel &current = getPixel(x, y);
            current.s += amount;
            if (current.s > 1.0)
            {
                current.s = 1.0;
            }
            if (current.s < 0.0)
            {
                current.s = 0.0;
            }
        }
    }
}

void Image::desaturate() {

    for (unsigned x = 0; x < width(); x++)
    {
        for (unsigned y = 0; y < height(); y++)
        {
            HSLAPixel &current = getPixel(x, y);
            current.s -= 0.1;
            if (current.s > 1.0)
            {
                current.s = 1.0;
            }
            if (current.s < 0.0)
            {
                current.s = 0.0;
            }
        }
    }
}

void Image::desaturate(double amount) {

    for (unsigned x = 0; x < width(); x++)
    {
        for (unsigned y = 0; y < height(); y++)
        {
            HSLAPixel &current = getPixel(x, y);
            current.s -= amount;
            if (current.s > 1.0)
            {
                current.s = 1.0;
            }
            if (current.s < 0.0)
            {
                current.s = 0.0;
            }
        }
    }
}

void Image::grayscale() {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            current.s = 0; 
        }
    }
}

void Image::rotateColor(double degrees) {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            current.h += degrees; 
            while (current.h > 360.0) 
            {
                current.h = 360.0; 
            }
            while (current.h < 0.0) 
            {
                current.h = 0.0;
            }
        }
    }
}

void Image::illinify() {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.l < 175 && current.l < 300) {
                current.l = 216; 
            } else {
                current.l = 11; 
            }
        }
    }
}

void Image::scale(double factor) {

    unsigned int W = width() * factor; 
    unsigned int H = height() * factor; 

    Image * scale = new Image(); 
    *scale = *this;

    resize(W, H);

    for (unsigned x = 0; x < W; x++)
    {
        for (unsigned y = 0; y < H; y++)
        {
            HSLAPixel & current = getPixel(x, y);
            HSLAPixel & scales = scale->getPixel(x / factor, y / factor);
            current = scales; 
        }
    }
}

void Image::scale(unsigned w, unsigned h) {
    double scaleW = float(w) / width();
    double scaleH = float(h) / height(); 

//easier and faster to use existing scale() to perform preservation 
    if (scaleW < scaleH) {
        scale(scaleW);
    } else {
        scale(scaleH);
    }
} 