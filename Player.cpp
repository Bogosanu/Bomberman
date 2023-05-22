
#include "Player.h"
#include "Exception.h"

Player::Player(){
    alive = true;
}

void Player::setSprite(const sf::Sprite &sprite1) {
    Player::sprite = sprite1;
}


void Player::setAlive(bool alive1) {
    Player::alive = alive1;
}

bool Player::isAlive() const {
    return alive;
}

Player *Player::clone() const {
    return new Player(*this);
}

Player::Player(const Player & other ) : Entity{other}, sprite{other.sprite}, alive{other.alive} {}

Player &Player::operator=(const Player & other) {
    Entity::operator=(other);
    alive = other.alive;
    sprite = other.sprite;
    return *this;
}

bool Player::can_be_placed(int x1, int y1, std::array<std::array<int,19>,13> m) {
    if(m[x1][y1] == 0)
        return true;
    return false;
}

void Player::setpos(int x1, int y1){ //exceptia e pentru inceput, cand sunt introduse coordonatele jucatorului din level.txt
        if (y1 >= 1 && y1 <= 17 && x1 >= 1 && x1 <= 11) { this->setX(x1); this->setY(y1); }
        else throw Outofbounds();
    }


Player::~Player() {}