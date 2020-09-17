/*************************************************************************************
 * Program Name: Space.hpp
 * Date: 6/2/19
 * Description: This is the Space class specification file. The Space class represents
 * a space on a map. This file declares the class data members and
 * methods.
 **************************************************************************************/

#ifndef FINALPROJECT_SPACE_HPP
#define FINALPROJECT_SPACE_HPP
#include <string>
#include "Player.hpp"
#include "foodItemType.hpp"

class Space {
protected:
    Space *top;
    Space *bottom;
    Space *right;
    Space *left;
    Player *player;
    foodItem item;
public:
    Space();
    Space(Space *t, Space *r, Space *b, Space *l, foodItem i);
    virtual ~Space() = default;
    virtual std::string getSpaceType() = 0; //pure virtual
    foodItem getItem();
    void setItem(foodItem);
    Space* getTop();
    Space* getBottom();
    Space* getRight();
    Space* getLeft();
    Player* getPlayer();
    void setTop(Space*);
    void setBottom(Space*);
    void setRight(Space*);
    void setLeft(Space*);
    void setPlayer(Player*);
    void setDirections(Space *t, Space *r, Space *b, Space *l);
};


#endif //FINALPROJECT_SPACE_HPP
