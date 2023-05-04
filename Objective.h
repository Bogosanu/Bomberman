#include "Entity.h"

#ifndef OOP_Objective_H
#define OOP_Objective_H


class Objective : public Entity{
private:
    sf::Sprite sprite;
    bool acquired;
public:
    Objective();

    Objective * clone() const override;

    Objective(const Objective& other);

    Objective& operator=(const Objective& other);

    bool can_be_placed(int, int, std::array<std::array<int,19>,13>);

    ~Objective();

    void setSprite(const sf::Sprite &sprite);

    void setAcquired(bool acquired);

    bool isAcquired() const;

};


#endif //OOP_Objective_H
