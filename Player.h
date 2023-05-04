#include "Entity.h"

#ifndef OOP_PLAYER_H
#define OOP_PLAYER_H


class Player : public Entity{
private:
    sf::Sprite sprite;
    bool alive;
public:
    Player();

    Player * clone() const override;

    Player(const Player& other);

    Player& operator=(const Player& other);

    bool can_be_placed(int, int, std::array<std::array<int,19>,13>);

    void setpos(int, int);

    ~Player();

    void setSprite(const sf::Sprite &sprite);

    void setAlive(bool alive);

    bool isAlive() const;

};


#endif //OOP_PLAYER_H
