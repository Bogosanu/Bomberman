
#include "Exception.h"
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

/*bool Objective::isAcquired() const {
    return acquired;
}*/

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
void Objective::setpos(int x1, int y1){ //exceptia e pentru inceput, cand sunt introduse coordonatele obiectivelor din level.txt
        if (y1 >= 1 && y1 <= 17 && x1 >= 1 && x1 <= 11) { this->setX(x1); this->setY(y1); }
        else throw Outofbounds();
    }



Objective::~Objective() {}