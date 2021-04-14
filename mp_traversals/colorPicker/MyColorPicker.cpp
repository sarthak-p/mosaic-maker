#include "../cs225/HSLAPixel.h"
#include "../Point.h"

#include "ColorPicker.h"
#include "MyColorPicker.h"

using namespace cs225;
MyColorPicker::MyColorPicker(double saturation)
    : saturation(saturation) {}
/**
 * Picks the color for pixel (x, y).
 * Using your own algorithm
 */
HSLAPixel MyColorPicker::getColor(unsigned x, unsigned y) {
  /* @todo [Part 3] */
  double newSat = ((double)(x * saturation)) + ((double)(y * saturation)); 
  return HSLAPixel(225, newSat, 0.33, 1.0);
}
