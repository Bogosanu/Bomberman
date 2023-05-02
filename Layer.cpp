
#include "Layer.h"
    Layer::Layer() {
        for(int i=0; i<19; ++i)
            row[i]=Brick();
    }
    Layer::Layer(std::array<Brick, 19> &row) : row(row) {}

    std::array<Brick, 19> &Layer::getRow()  {
        return row;
    }
