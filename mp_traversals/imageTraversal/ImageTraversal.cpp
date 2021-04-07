#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traverse = nullptr; 
  startPoint_ = Point(0, 0);
}

/**
 * Custom iterator constructor.
 */
ImageTraversal::Iterator::Iterator(ImageTraversal * t, PNG & png, Point & start, double tolerance) {
  traverse = t;
  png_ = png;
  tol_ = tolerance;
  startPoint_ = start; 

  traversed = new bool * [png_.width()];

  for (unsigned int x = 0; x < png_.width(); x++) {
    traversed[x] = new bool[png_.height()];
  }

  //initially all points are unvisited 
  for (unsigned int x = 0; x < png_.width(); x++) {
    for (unsigned int y = 0; y < png_.height(); y++) {
      traversed[x][y] = false;
    }
  }
  //adding startPoint to our data structure 
  traverse->add(startPoint_);
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator &ImageTraversal::Iterator::operator++() {
  //starting point initially  
  curr = traverse->pop();
  traversed[curr.x][curr.y] = true; 

  //neighbors
  Point right = Point(curr.x + 1, curr.y);
  Point down = Point(curr.x, curr.y + 1);
  Point left = Point(curr.x - 1, curr.y);
  Point up = Point(curr.x, curr.y - 1);
    
  //adding all points within tolerance and range to the traversal 
  if (right.x < png_.width() && right.y < png_.height()) {
    if (traversed[right.x][right.y] == false) {
      double within0 = calculateDelta(png_.getPixel(curr.x, curr.y), png_.getPixel(startPoint_.x, startPoint_.y));
      if (within0 < tol_) {
        traverse->add(right);
      }
    }
  }

  if (down.x < png_.width() && down.y < png_.height()) {
    if (traversed[down.x][down.y] == false) {
      double within1 = calculateDelta(png_.getPixel(startPoint_.x, startPoint_.y), png_.getPixel(curr.x, curr.y));
      if (within1 < tol_) {
        traverse->add(down);
      }
    }
  }

  if (left.x < png_.width() && left.y < png_.height()) {
    if (traversed[left.x][left.y] == false) {
      double within2 = calculateDelta(png_.getPixel(startPoint_.x, startPoint_.y), png_.getPixel(curr.x, curr.y));
      if (within2 < tol_) {
        traverse->add(left);
      }
    }
  }

  if (up.x < png_.width() && up.y < png_.height()) {
      if (traversed[up.x][up.y] == false) {
        double within3 = calculateDelta(png_.getPixel(startPoint_.x, startPoint_.y), png_.getPixel(curr.x, curr.y));
        if (within3 < tol_) {
          traverse->add(up);
        }
      }
    }
    
    if (!traverse->empty()) {
      if (traversed[traverse->peek().x][traverse->peek().y]) {
        curr = traverse->peek(); 
      }
    }
    return *this; 
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  return traverse->peek(); 
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  return false; 
}
    
