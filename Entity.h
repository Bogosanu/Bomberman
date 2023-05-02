

#ifndef OOP_ENTITY_H
#define OOP_ENTITY_H


class Entity {
private:
    int x,y;
public:
    Entity();

    int getX() const;

    int getY() const;

    Entity(int x_, int y_);


    void setX(int x);

    void setY(int y);

    void setpos(int, int);

};


#endif //OOP_ENTITY_H
