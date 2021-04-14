
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.

  //reading the base image 
  PNG base;  
  base.readFromFile("tests/cap.png");

  FloodFilledImage flood(base);

  DFS a(base, Point(60, 60), 0.5);
  DFS b(base, Point(100, 100), 0.5);
 
  MyColorPicker custom(0.5); 

  flood.addFloodFill(a, custom);
  flood.addFloodFill(b, custom);
 
  Animation animation = flood.animate(5000); 

  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  return 0;
}
