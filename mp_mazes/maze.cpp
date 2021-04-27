/* Your code here! */
#include "maze.h"
#include "cs225/HSLAPixel.h"
#include "cs225/PNG.h"
#include <vector>
#include "dsets.h"
#include <iostream>
#include <sys/time.h>
#include <cmath>

using namespace std; 
using namespace cs225; 

SquareMaze::SquareMaze() {}

void SquareMaze::makeMaze(int width, int height) {
    width_ = width; 
    height_ = height;

    //initialize a new grid of width * height 
    disjoint.addelements(width_ * height_);

    //cout << "here" << endl;

    //initially the grid has all the walls (true if exists, false if does not exist)
    for (int i = 0; i < width_ * height_; i++) {
        right_.push_back(true);
        down_.push_back(true);
    }

    //randomly select walls in the grid to delete 
    while (disjoint.size(0) < (width_ * height_)) {
        int x = rand() % width_; 
        int y = rand() % height_; 
        int check = rand() % 2;

        //two bits of data
        //right since 0 
        if (check == 0) {
            if (x != width_ - 1) { //check perimeter 
                if (right_[x + y * width_] == true) {  //wall exists?                                                                         
                    if (disjoint.find(x + y * width_) != disjoint.find((x + 1) + y * width_)) { //prevent cycle                                          
                        disjoint.setunion(x + y * width_, (1 + x) + y * width_); //remove the wall 
                        setWall(x, y, 0, false); //set wall to `false since it doesn't exist anymore
                    }
                }
            }
        }
        //down size 1 
        if (check == 1) {
            if (y != height_ - 1) {
                if (down_[x + y * width_] == true) {
                    if (disjoint.find(x + y * width_) != disjoint.find(x + (y + 1) * width_)) {
                        disjoint.setunion(x + y * width_, x + (y + 1) * width_);
                        setWall(x, y, 1, false);
                    }
                }
            }
        }
    }
}
            

bool SquareMaze::canTravel(int x, int y, int dir) const {
    
    //dir = 0 represents a rightward step (+1 to the x coordinate)
    //dir = 1 represents a downward step (+1 to the y coordinate)
    //dir = 2 represents a leftward step (-1 to the x coordinate)
    //dir = 3 represents an upward step (-1 to the y coordinate)

   if (dir == 0) {
       return right_[x + y * width_] == false; 
   } else if (dir == 2 and x != 0) {
       return right_[(x - 1) + y * width_] == false;
   } else if (dir == 1) {
       return down_[x + y  * width_] == false; 
   } else if (dir == 3 && y != 0) {
       return down_[x + (y - 1) * width_] == false; 
   }
   //all other cases return false 
   return false;
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {

    if (dir == 1) {
        down_[x + y * width_] = exists; 
    } else if (dir == 0) {
        right_[x + y * width_] = exists; 
    }
}

vector<int> SquareMaze::solveMaze() {
    return vector<int>();
}

PNG * SquareMaze::drawMaze() const {

    //PNG with (width*10+1,height*10+1) dimensions 
    PNG * out = new PNG(width_ * 10 + 1, height_ * 10 + 1);

    //Blacken the entire topmost row and leftmost column of pixels, except the entrance(1, 0) through(9, 0)
    for (int w = 10; w < width_ * 10 + 1; w++) {
        for (int h = 0; h < height_ * 10 + 1; h++) {
            HSLAPixel & row = out->getPixel(w, 0);
            HSLAPixel & col = out->getPixel(0, h);
            row.l = col.l = 0; 
        }
    }

    //iterating through each square in the maze 
    for (int i = 0; i < width_; i++) {
        for (int j = 0; j < height_; j++) {
            //blacken the pixels with coordinates ((x+1)*10,y*10+k) for k from 0 to 10
            if (right_[i + j * width_] == true) { //check if the walls exist 
                for (int k = 0; k <= 10; k++) { 
                    HSLAPixel & right = out->getPixel((i + 1) * 10, j * 10 + k);
                    right.l = 0; 
                }
            }
            //blacken the pixels with coordinates (x*10+k, (y+1)*10) for k from 0 to 10
            if (down_[i + j * width_] == true) {
                for (int k = 0; k <= 10; k++) {
                    HSLAPixel & down = out->getPixel(i * 10 + k, (j + 1) * 10);
                    down.l = 0;
                }
            }
        }
    }
    return out;
}

PNG *SquareMaze::drawMazeWithSolution() {
    return nullptr; 
}







