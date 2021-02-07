#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
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
      HSLAPixel & ourPixel = ourPNG->getPixel(x, y); 
      HSLAPixel & newPixel = newPNG.getPixel(ourPNG->width() - x - 1, ourPNG->height() - y - 1);

      newPixel = ourPixel; 
    }
  }
  newPNG.writeToFile(outputFile);
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3

  

  return png;
}
