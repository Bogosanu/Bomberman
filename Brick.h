
#ifndef OOP_BRICK_H
#define OOP_BRICK_H


class Brick {
private:
    int hp;
    int x,y;
    bool alive;
public:
    Brick();
    Brick(int hp_, int x_, int y_, bool alive_);
    Brick(const Brick& other);

    int gethp() const;
    int getx() const;

    Brick& operator=(const Brick& other);

    ~Brick();

    void setY(int);

    void setHp(int);

    void setAlive(bool);

    void setX(int);

    void setdetails(int, int, int);

    void damagebrick();

};


#endif //OOP_BRICK_H
