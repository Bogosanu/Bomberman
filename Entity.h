#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <array>
#include <iostream>

class Entity {
private:
    int x,y;
public:
    Entity();


    virtual Entity * clone() const = 0;

    Entity& operator=(const Entity& other);

    Entity(int x_, int y_);

    Entity(const Entity& other);

    int getX() const;

    int getY() const;


    void setX(int x);

    void setY(int y);

    //void setpos(int, int);

    void configure_sprite(sf::Sprite);

    virtual bool can_be_placed(int,int, std::array<std::array<int,19>,13>) = 0;

    virtual void setpos(int, int) = 0;

    virtual ~Entity();
};


#endif //OOP_ENTITY_H
