
#ifndef OOP_GAME_H
#define OOP_GAME_H
#include "Entity.h"
#include "Brick.h"
#include "Layer.h"
#include "Wall.h"
#include <fstream>
#include <array>
#include <iostream>
#include <vector>


class Game {
    Wall mbr;
    std::array<std::array<int,19>,13> m{{{0}}};

public:
    [[nodiscard]] const std::array<std::array<int, 19>, 13> &getM() const;
    Game();
    Wall &getMbr();
    void generatelevel();
    void drawlevel();

};


#endif //OOP_GAME_H
