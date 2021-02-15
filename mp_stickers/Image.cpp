#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace cs225; 

void Image::lighten() {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.l > 1.0) {
                current.l = 1.0;
            } else if (current.l < 0.0){
                current.l = 0.0;
            } else {
                current.l += 0.1;
            }
        }
    }
}

void Image::lighten(double amount) {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.l > 1.0) {
                current.l = 1.0; 
            } else if (current.l < 0.0){
                current.l = 0.0;
            } else {
                current.l += amount;
            }
        }
    }
}

void Image::darken() {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.h > 1.0) {
                current.l = 1.0;
            } else if (current.l < 0.0){
                current.l = 0.0;
            } else {
                current.l -= 0.1;
            }
        }
    }
}

void Image::darken(double amount) {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.l > 1.0) {
                current.l = 1.0; 
            } else if (current.l < 0.0){
                current.l = 0.0;
            } else {
                current.l -= amount;
            }
        }
    }
}

void Image::saturate() {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.s > 1.0) {
                current.s = 1.0; 
            } else if (current.l < 0.0){
                current.s = 0.0;
            } else {
                current.s += 0.1;
            }
        }
    }
}

void Image::saturate(double amount) {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.s > 1.0) {
                current.s = 1.0; 
            } else if (current.s < 0.0){
                current.s = 0.0;
            } else {
                current.s += amount;
            }
        }
    }
}

void Image::desaturate() {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.s > 1.0) {
                current.s = 1.0; 
            } else if (current.s < 0.0){
                current.s = 0.0;
            } else {
                current.s -= 0.1;
            }
        }
    }
}

void Image::desaturate(double amount) {

    for (unsigned x = 0; x < width(); x++) {
        for (unsigned y = 0; y < height(); y++) {
            HSLAPixel & current = getPixel(x, y);
            if (current.s > 1.0) {
                current.s = 1.0; 
            } else if (current.s < 0.0){
                current.s = 0.0;
            } else {
                current.s += amount;
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
            if (current.h > 360.0) {
                current.h = 360.0; 
            } else if (current.h < 0.0) {
                current.h = 0.0;
            } else {
                current.h += degrees; 
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

