#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>


void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 

  PNG & ourPNG = new PNG();
  ourPNG = readFromFile(inputFile);

  PNG & newPNG = new PNG();
  newPNG = readFromFile(outputFile);

  


  
}
cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  // TODO: Part 3

  return png;
}
