

#include "Objective.h"


Objective::Objective(){
    acquired = false;
}

void Objective::setSprite(const sf::Sprite &sprite) {
    Objective::sprite = sprite;
}

void Objective::setAcquired(bool acquired) {
    Objective::acquired = acquired;
}

bool Objective::isAcquired() const {
    return acquired;
}

Objective *Objective::clone() const {
    return new Objective(*this);
}

Objective::Objective(const Objective & other ) : acquired{other.acquired}, sprite{other.sprite} {}

Objective &Objective::operator=(const Objective & other) {
    acquired = other.acquired;
    sprite = other.sprite;
    return *this;
}

bool Objective::can_be_placed(int x, int y, std::array<std::array<int,19>,13> m) {
    if(m[x][y] == 1) // obiectivele stau pe caramizi destructibile si trb sa fie distruse pt a castiga
        return true;
    return false;
}

Objective::~Objective() {}