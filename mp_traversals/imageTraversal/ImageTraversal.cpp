#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
using namespace std; 

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
  traverse = NULL; 
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
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {

  //starting point initially  
  curr = traverse->pop();
  //set the point to true since we have visited it 
  traversed[curr.x][curr.y] = true; 

  //neighbors
  Point right = Point(curr.x + 1, curr.y);
  Point down = Point(curr.x, curr.y + 1);
  Point left = Point(curr.x - 1, curr.y);
  Point up = Point(curr.x, curr.y - 1);

  //adding all neighbors within tolerance and range to the traversal (if unvisited)
  if (right.x < png_.width() && right.y < png_.height()) {
    if (traversed[right.x][right.y] != true) {
      double within = calculateDelta(png_.getPixel(right.x, right.y), png_.getPixel(startPoint_.x, startPoint_.y));
      if (within <= tol_) {
        traverse->add(right);
      }
    }
  }

  if (down.y < png_.height() && down.x < png_.width()) {
    if (traversed[down.x][down.y] != true) {
      double within = calculateDelta(png_.getPixel(down.x, down.y), png_.getPixel(startPoint_.x, startPoint_.y));
      if (within <= tol_) {
        traverse->add(down);
      }
    }
  }

  if (left.y < png_.height() && left.x < png_.width()) {
    if (traversed[left.x][left.y] != true) {
      double within = calculateDelta(png_.getPixel(left.x, left.y), png_.getPixel(startPoint_.x, startPoint_.y));
      if (within <= tol_) {
        traverse->add(left);
      }
    }
  }

  if (up.y < png_.height() && up.x < png_.width()) {
    if (traversed[up.x][up.y] != true) {
      double within = calculateDelta(png_.getPixel(up.x, up.y), png_.getPixel(startPoint_.x, startPoint_.y));
      if (within <= tol_) {
        traverse->add(up);
      }
    }
  }

    //current becomes next point in stack/queue
    curr = traverse->peek();

    //if traverse is not empty, then pop the point 
    while (!traverse->empty()) {
      if (traversed[curr.x][curr.y]) {
        curr = traverse->pop();
      } else {
        break; 
      }
    }
    return *this; 
}
      

    /**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*()
  {
      Point first_in_line = traverse->peek();
      return first_in_line;  
  }

      /**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
  bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other){
    bool size1 = traverse->empty(); 
    //bool size2 = other.traverse->empty(); 
    return (size1 == false); 
  }
    
