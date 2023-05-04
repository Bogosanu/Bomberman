#include "Entity.h"

//Clasa Abstracta

Entity::Entity() {};


Entity::Entity(int x_, int y_) : x{x_}, y{y_} {}


Entity *Entity::clone() const {
    return nullptr;
}


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


void Entity::set_sprite(sf::Sprite sprite) {
    sprite.setPosition(y*50,x*50);
    sprite.setScale(0.5f, 0.5f);
}



bool Entity::can_be_placed(int x, int y, std::array<std::array<int,19>,13> m) {
    if(x >= 1 && x <= 17 && y >= 1 && y <= 11)
        return true;
    else return false;

}

Entity::~Entity() {}