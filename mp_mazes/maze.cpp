/* Your code here! */
#include "maze.h"
#include "cs225/PNG.h"
#include <vector>

using namespace std; 
using namespace cs225; 

SquareMaze::SquareMaze() {}

void SquareMaze::makeMaze(int width, int height) {
    width_ = width; 
    height_ = height; 

    
}

bool SquareMaze::canTravel(int x, int y, int dir) const {
    return false; 
}

void SquareMaze::setWall(int x, int y, int dir, bool exists) {

}

vector<int> SquareMaze::solveMaze() {

}

PNG * SquareMaze::drawMaze() const {
    
}

PNG *SquareMaze::drawMazeWithSolution() {

}







