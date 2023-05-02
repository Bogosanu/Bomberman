
#ifndef OOP_LAYER_H
#define OOP_LAYER_H
#include <array>
#include "Brick.h"

class Layer {
private:
    std::array<Brick,19> row;
public:
    Layer();
    Layer(std::array<Brick, 19> &row);
    std::array<Brick, 19> &getRow();
};


#endif //OOP_LAYER_H
