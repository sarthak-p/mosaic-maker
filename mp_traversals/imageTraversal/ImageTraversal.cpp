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
  //Every ImageTraversal is initialized with a start point
  curr = Point(0, 0); 
}

/**
 * Custom iterator constructor.
 */
// ImageTraversal::Iterator::Iterator(ImageTraversal * t, PNG & png, Point & start, double tolerance)
// {
//   curr = p; 
//   traverse = t;
//   png_ = png; 
//   tol_ = tolerance; 
//   startPoint = start; 
// }

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */

  //neighbors of the point 
  // Point right = Point(curr.x + 1, curr.y);
  // Point down = Point(curr.x, curr.y + 1);
  // Point left = Point(curr.x - 1, curr.y);
  // Point up = Point(curr.x, curr.y - 1);

  // if (png_.width() > right.x) {
  //   if (visited_[right] != true) {
  //     double within0 = calculateDelta(png_.getPixel(right.x, right.y), png_.getPixel(startPoint.x, startPoint.y);
  //     if (within0 <= tol_) {
  //       traverse->add(right);
  //     }
  //   }
  // }

  // if (png_.height() > down.x) {
  //   if (visited_[down] != true) {
  //     double within1 = calculateDelta(png_.getPixel(down.x, down.y), png_.getPixel(startPoint.x, startPoint.y);
  //     if (within1 <= tol_) {
  //       traverse->add(down);
  //     }
  //   }
  // }

  // if (png_.width() > left.x) {
  //   if (visited_[left] != true) {
  //     double within2 = calculateDelta(png_.getPixel(left.x, left.y), png_.getPixel(startPoint.x, startPoint.y);
  //     if (within2 <= tol_) {
  //       traverse->add(left);
  //     }
  //   }
  // }

  // if (png_.height() > up.y) {
  //   if (visited_[up] != true) {
  //     double within3 = calculateDelta(png_.getPixel(up.x, up.y), png_.getPixel(startPoint.x, startPoint.y);
  //     if (within3 <= tol_) {
  //       traverse->add(up);
  //     }
  //   }
  // }
  // return *this;

  return *this; 


}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return Point(0, 0);
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  return false;
}
