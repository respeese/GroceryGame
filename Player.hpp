/*************************************************************************************
 * Program Name: Player.hpp
 * Date: 6/10/19
 * Description: This is the Player class specification file. The Player class
 * represents the user in a grocery store. This file declares the
 * class data members and methods.
 **************************************************************************************/

#ifndef FINALPROJECT_PLAYER_HPP
#define FINALPROJECT_PLAYER_HPP
#include "GroceryList.hpp"

class Player {
private:
    int energy;
    int row;
    int col;
    GroceryList basket; //holds 15 items
    bool dead;
public:
    Player();
    Player(int, int);
    void move(int direction);
    void addBasket(foodItem item);
    void removeBasket(foodItem item);
    void printBasket();
    void printBasketSize();
    GroceryList getBasket();
    void setBasket(GroceryList b);
    int getRow();
    int getCol();
    void setRow(int r);
    void setCol(int c);
    int getEnergy();
    void setEnergy(int);
    void setDead(bool status);
    bool getDead();
};


#endif //FINALPROJECT_PLAYER_HPP
