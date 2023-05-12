

#include "Objective.h"


Objective::Objective(){
    acquired = false;
}

void Objective::setSprite(const sf::Sprite &sprite1) {
    Objective::sprite = sprite1;
}

void Objective::setAcquired(bool acquired1) {
    Objective::acquired = acquired1;
}

bool Objective::isAcquired() const {
    return acquired;
}

Objective *Objective::clone() const {
    return new Objective(*this);
}

Objective::Objective(const Objective & other ) : Entity{other}, sprite{other.sprite}, acquired{other.acquired} {}

Objective &Objective::operator=(const Objective & other) {
    Entity::operator=(other);
    acquired = other.acquired;
    sprite = other.sprite;
    return *this;
}

bool Objective::can_be_placed(int x1, int y1, std::array<std::array<int,19>,13> m) {
    if(m[x1][y1] == 1) // obiectivele stau pe caramizi destructibile si trb sa fie distruse pt a castiga
        return true;
    return false;
}

Objective::~Objective() {}