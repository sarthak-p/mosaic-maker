#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <cmath>
using namespace cs225; 

#include <string>


void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 

  //created a new PNG pointer that loads inputFile
  PNG * ourPNG = new PNG(); 
  ourPNG->readFromFile(inputFile); 

  //created regular PNG variable to write output image 
  PNG newPNG(ourPNG->width(), ourPNG->height()); 

for (unsigned int x = 0; x < ourPNG->width(); x++) { 
  for (unsigned int y = 0; y < ourPNG->height(); y++) {
      
      HSLAPixel & newPixel = newPNG.getPixel(ourPNG->width() - x - 1, ourPNG->height() - y - 1);

      HSLAPixel & ourPixel = ourPNG->getPixel(x, y); 

      newPixel = ourPixel; 
    }
  }
  newPNG.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3

  unsigned int centerX = png.width() / 2; 
  unsigned int centerY = png.height() / 2; 
  unsigned int topY = png.height() / 3; 
  unsigned int middleY = png.height() * 0.66;  


  for (unsigned int x = 0; x < png.width(); x++) {
    for (unsigned int y = 0; y < png.height(); y++) {

      HSLAPixel & current = png.getPixel(x, y); 
      current.h = 285; 
      current.s = 0.18; 
      current.l = 0.8;

      unsigned int k = 11000; 


      if (y <= topY) {
        current.h = 31; 
        current.s = 0.85;
        current.l = 0.40; 
      } else if (topY < y && y <= middleY) {
        current.h = 360; 
        current.s = 1.0;
        current.l = 1.0;
      } else {
        current.h = 95; 
        current.s = 0.38; 
        current.l = 0.28; 
      }

      if (((x - centerX)*(x - centerX)) + (y - centerY)*(y - centerY) <= (k^2)) {
        current.h = 241; 
        current.s = 1.0; 
        current.l = 0.4; 
      }
    }
  }
  return png;
}
