
#include "Player.h"
#include "Exception.h"
#include <iostream>

Player::Player(){
    alive = true;
}

void Player::setSprite(const sf::Sprite &sprite) {
    Player::sprite = sprite;
}

void Player::setAlive(bool alive) {
    Player::alive = alive;
}

bool Player::isAlive() const {
    return alive;
}

Player *Player::clone() const {
    return new Player(*this);
}

Player::Player(const Player & other ) : alive{other.alive}, sprite{other.sprite} {}

Player &Player::operator=(const Player & other) {
    alive = other.alive;
    sprite = other.sprite;
    return *this;
}

bool Player::can_be_placed(int x, int y, std::array<std::array<int,19>,13> m) {
    if(m[x][y] == 0)
        return true;
    return false;
}

void Player::setpos(int x1, int y1){
    try {
        if (y1 >= 1 && y1 <= 17 && x1 >= 1 && x1 <= 11) { this->setX(x1); this->setY(y1); }
        else throw Outofbounds();
    }
    catch (const Exception& e) {
        std::cout<<"Error: "<<e.what();
    }
}


Player::~Player() {}