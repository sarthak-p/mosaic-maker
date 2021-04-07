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
  traverse = nullptr; 
}

/**
 * Custom iterator constructor.
 */
ImageTraversal::Iterator::Iterator(ImageTraversal * t, PNG & png, Point & start, double tolerance) {
  traverse = t;
  png_ = png;
  tol_ = tolerance;
  startPoint = start;

  traversed = new int * [png_.width()];

  for (unsigned x = 0; x < png_.width(); x++) {
    traversed[x] = new int[png_.height()];
  }

  for (unsigned x = 0; x < png_.width(); x++) {
    for (unsigned y = 0; y < png_.height(); y++) {
      traversed[x][y] = 0;
    }
  }
  traverse->add(startPoint);
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {

  if (!traverse->empty() )
  traversed[(int)traverse->pop().x][(int)traverse->pop().y] = 1;

  curr = traverse->pop(); 

  //neighbors of the point
  Point right = Point(curr.x + 1, curr.y);
  Point down = Point(curr.x, curr.y + 1);
  Point left = Point(curr.x - 1, curr.y);
  Point up = Point(curr.x, curr.y - 1);

  if (png_.width() > right.x) {
    if (traversed[curr.x + 1][curr.y] != 1) {
      double within0 = calculateDelta(png_.getPixel(curr.x, curr.y), png_.getPixel(startPoint.x, startPoint.y));
      if (within0 <= tol_) {
        traverse->add(right);
      }
    }
  }

    if (png_.height() > down.y) {
      if (traversed[curr.x][curr.y + 1] != 1) {
        double within1 = calculateDelta(png_.getPixel(curr.x, curr.y), png_.getPixel(startPoint.x, startPoint.y));
        if (within1 <= tol_) {
          traverse->add(down);
        }
      }
    }

    if (0 > left.x) {
      if (traversed[curr.x - 1][curr.y] != 1) {
        double within2 = calculateDelta(png_.getPixel(curr.x, curr.y), png_.getPixel(startPoint.x, startPoint.y));
        if (within2 <= tol_) {
          traverse->add(left);
        }
      }
    }

    if (0 > up.y) {
      if (traversed[curr.x][curr.y - 1] != 1) {
        double within3 = calculateDelta(png_.getPixel(curr.x, curr.y), png_.getPixel(startPoint.x, startPoint.y));
        if (within3 <= tol_) {
          traverse->add(up);
        }
      }
    }

    if (!traverse->empty()) {
      curr = traverse->peek();
    }
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
