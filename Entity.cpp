#include "Entity.h"

//Clasa Abstracta

Entity::Entity() {};


Entity::Entity(int x_, int y_) : x{x_}, y{y_} {}

Entity::Entity(const Entity & other ) : x{other.x}, y{other.y} {}

Entity *Entity::clone() const {
    return nullptr;
}


Entity& Entity::operator=(const Entity & other) {
    x = other.x;
    y = other.y;
    return *this;
}

int Entity::getX() const {
    return x;
}

int Entity::getY() const {
    return y;
}

void Entity::setX(int x1) {
    Entity::x = x1;
}

void Entity::setY(int y1) {
    Entity::y = y1;
}


void Entity:: configure_sprite(sf::Sprite sprite) {
    sprite.setScale(0.5f, 0.5f);
    sprite.setPosition(y*50,x*50);
}



 bool Entity::can_be_placed(int x1, int y1, std::array<std::array<int,19>,13> m) {
    return (x1 >= 1 && x1 <= 17 && y1 >= 1 && y1 <= 11 && (m[x1][y1] == 0 || m[x1][y1] == 1));


}

Entity::~Entity() {}