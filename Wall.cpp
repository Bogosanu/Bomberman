
#include "Wall.h"

    Wall::Wall() {
        for(int i=0; i<13; ++i)
            wallmatrix[i]=Layer();
    }

    Wall::Wall(std::array<Layer, 13> &wallmatrix) : wallmatrix(wallmatrix) {}


    std::array<Layer, 13> &Wall::getWallmatrix()  {
        return wallmatrix;
    }


