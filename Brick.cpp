#include "Brick.h"
#include <iostream>

    Brick::Brick()
    {
        hp = 0;
        x = 0;
        y = 0;
        alive = 0;

    }
    Brick::Brick(int hp_, int x_, int y_, bool alive_) : hp{hp_}, x{x_}, y{y_}, alive{alive_} {}
    Brick::Brick(const Brick& other) : hp{other.hp}, x{other.x}, y{other.y}, alive{other.alive} {}  //constructor de copiere

    int Brick::gethp() const { return hp; }
    // int Brick::getx() const { return x; }
    //   int gety() const { return y; }
    //   int isalive() const { return alive; }




    Brick& Brick::operator=(const Brick& other) {
        hp = other.hp;
        x = other.x;
        y = other.y;
        alive = other.alive;
        return *this;
    }


    Brick::~Brick() = default;

    void Brick::setY(int y1) {
        Brick::y = y1;
    }


    void Brick::setHp(int hp1) {
        Brick::hp = hp1;
    }

    void Brick::setAlive(bool alive1) {
        Brick::alive = alive1;
    }

    void Brick::setX(int x1) {
        Brick::x = x1;
    }



    void Brick::setdetails(int x_, int y_, int hp_) {
        this->setX(x_);
        this->setY(y_);
        this->setHp(hp_);
        if(hp_>0)
            this->setAlive(true);
        else this->setAlive(false);
    }

    void Brick::damagebrick(){
        if(this->hp != 0 && this->hp < 9) // caramizile cu 1 hp sunt destructibile
            this->setHp(this->hp-1);  // caramizile cu 2 hp sunt obiective
        if(this->hp == 0)
            this->setAlive(false);
    }


