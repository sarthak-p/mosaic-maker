/* Your code here! */
#include "maze.h"
#include "cs225/PNG.h"
#include <vector>
#include "dsets.h"

using namespace std; 
using namespace cs225; 

SquareMaze::SquareMaze() {
    width_ = 0; 
    height_ = 0; 
}

void SquareMaze::makeMaze(int width, int height) {
    // width_ = width; 
    // height_ = height; 

    // disjoint.addelements(height_ * width_); 
    // int i = 0; 
    // while (i < width_) {
    //     right_.push_back(true); 
    //     down_.push_back(true);
    // }

    // while(disjoint.size())

}

bool SquareMaze::canTravel(int x, int y, int dir) const {
    return false; 
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {

}

vector<int> SquareMaze::solveMaze() {
    return vector<int>();
}

PNG * SquareMaze::drawMaze() const {
    return nullptr; 
}

PNG *SquareMaze::drawMazeWithSolution() {
    return nullptr; 
}







