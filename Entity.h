#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Entity {
private:
    int x,y;
public:
    Entity();


    virtual Entity * clone() const = 0;

    Entity(int x_, int y_);

    int getX() const;

    int getY() const;


    void setX(int x);

    void setY(int y);

    //void setpos(int, int);

    void set_sprite(sf::Sprite);

    virtual bool can_be_placed(int,int, std::array<std::array<int,19>,13>) = 0;

    virtual ~Entity();
};


#endif //OOP_ENTITY_H
