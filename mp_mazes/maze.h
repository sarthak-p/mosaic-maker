/* Your code here! */
#pragma once
#include "dsets.h"

#include <vector>
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

using namespace std;
using namespace cs225; 

class SquareMaze {
public:
    SquareMaze(); 
    bool canTravel(int x, int y, int dir) const;
    PNG * drawMaze() const; 
    PNG * drawMazeWithSolution(); 
    void makeMaze(int width, int height);
    void setWall(int x, int y, int dir, bool exists);
    vector<int> solveMaze(); 


private:
    int width_; 
    int height_; 
    DisjointSets disjoint; 
    vector<bool> right_; 
    vector<bool> down_; 
};