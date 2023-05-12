
#ifndef OOP_GAME_H
#define OOP_GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Entity.h"
#include "Brick.h"
#include "Layer.h"
#include "Wall.h"
#include "Player.h"
#include "Objective.h"
#include "Exception.h"
#include <fstream>
#include <array>
#include <iostream>
#include <vector>
#include <memory>

class Game {
    Wall mbr;
    std::array<std::array<int,19>,13> m{{{0}}};
    Player player;
    std::vector<std::shared_ptr<Objective>> obj;

public:
    [[nodiscard]] const std::array<std::array<int, 19>, 13> &getM() const;
    Game();
    Wall &getMbr();
    void generatelevel();
    void drawlevel();



};


#endif //OOP_GAME_H
