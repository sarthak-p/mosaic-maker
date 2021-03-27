/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;

Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    map<Point<3>, long> tiles;
    vector<Point<3>> pixelPoints;

    for (unsigned long i = 0; i < theTiles.size(); i++) {
        Point<3> converted = convertToXYZ(theTiles[i].getAverageColor());
        tiles[converted] = i;
        pixelPoints.push_back(converted);
    }

    MosaicCanvas * output = new MosaicCanvas(theSource.getRows(), theSource.getColumns());
    KDTree<3> pointTree(pixelPoints); 

    for (int r = 0; r < theSource.getRows(); r++) { 
        for (int c = 0; c < theSource.getColumns(); c++) {
            Point<3> converted1 = convertToXYZ(theSource.getRegionColor(r, c));
            output->setTile(r, c, &theTiles[tiles[pointTree.findNearestNeighbor(converted1)]]);
        }
    }
    return output; 
}
