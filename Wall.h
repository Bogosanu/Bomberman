
#ifndef OOP_WALL_H
#define OOP_WALL_H
#include <array>
#include "Layer.h"

class Wall {
private:

    std::array<Layer,13> wallmatrix;

public:
    Wall();
    Wall(std::array<Layer, 13> &wallmatrix);
    std::array<Layer, 13> &getWallmatrix();
};


#endif //OOP_WALL_H
