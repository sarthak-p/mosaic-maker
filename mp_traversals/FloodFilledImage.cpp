#include "cs225/PNG.h"
#include <list>
#include <vector>
#include <iostream>
#include <queue>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;
using namespace std; 

/**
 * Constructs a new instance of a FloodFilledImage with a image `png`.
 * 
 * @param png The starting image of a FloodFilledImage
 */
FloodFilledImage::FloodFilledImage(const PNG & png) {
  /** @todo [Part 2] */
  png_ = png; 
}

/**
 * Adds a FloodFill operation to the FloodFillImage.  This function must store the operation,
 * which will be used by `animate`.
 * 
 * 
 * @param traversal ImageTraversal used for this FloodFill operation.
 * @param colorPicker ColorPicker used for this FloodFill operation.
 */
void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
  traverser.push_back(&traversal);
  colorPicker_.push_back(&colorPicker);
}

/**
 * Creates an Animation of frames from the FloodFill operations added to this object.
 * 
 * Each FloodFill operation added by `addFloodFill` is executed based on the order
 * the operation was added.  This is done by:
 * 1. Visiting pixels within the image based on the order provided by the ImageTraversal iterator and
 * 2. Updating each pixel to a new color based on the ColorPicker
 * 
 * While applying the FloodFill to the image, an Animation is created by saving the image
 * after every `frameInterval` pixels are filled.  To ensure a smooth Animation, the first
 * frame is always the starting image and the final frame is always the finished image.
 * 
 * (For example, if `frameInterval` is `4` the frames are:
 *   - The initial frame
 *   - Then after the 4th pixel has been filled
 *   - Then after the 8th pixel has been filled
 *   - ...
 *   - The final frame, after all pixels have been filed)
 */ 
Animation FloodFilledImage::animate(unsigned frameInterval) const {
  Animation animation;

  //initial frame prior to any changes
  PNG duplicate = png_;
  animation.addFrame(duplicate);

  unsigned frameNum = 1;

  //visiting each pixel within the image based on the order provided by iterator 
  for (unsigned i = 0; i < traverser.size(); i++) {
    for (Point pixelPoint : *traverser[i]) {
      HSLAPixel & pixel = duplicate.getPixel(pixelPoint.x, pixelPoint.y);
      HSLAPixel colorPixel = colorPicker_[i]->getColor(pixelPoint.x, pixelPoint.y);
      pixel.h = colorPixel.h;
      pixel.s = colorPixel.s;
      pixel.l = colorPixel.l;
      pixel.a = colorPixel.a;
      //cout << frameNum << endl; 
      //pixel.a = colorPicker_[i]->getColor(pixelPoint.x, pixelPoint.y).a;

      //adding every "frameInterval"th pixel to animation 
      if (frameNum % frameInterval == 0) {
        animation.addFrame(duplicate);
      }
      frameNum++;
    }
  }
  //final frame
  animation.addFrame(duplicate);
  return animation;
}
