#include "Exception.h"
#include "Entity.h"
#include "Game.h"


Entity::Entity() {};

Entity::Entity(int x_, int y_) : x{x_}, y{y_} {}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

void Entity::setX(int x) {
    Entity::x = x;
}

void Entity::setY(int y) {
    Entity::y = y;
}

void Entity::setpos(int x1, int y1){
    try {
        if (y1 >= 1 && y1 <= 17 && x1 >= 1 && x1 <= 12) { this->setX(x1); this->setY(y1); }
        else throw Outofbounds();
    }
    catch (const Exception& e) {
        std::cout<<"Error: "<<e.what();
    }
}
