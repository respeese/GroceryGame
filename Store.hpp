/*************************************************************************************
 * Program Name: Store.hpp
 * Date: 6/11/19
 * Description: This is the Store class specification file. The Store class represents
 * a grocery store. This file declares the class data members and methods.
 **************************************************************************************/

#ifndef FINALPROJECT_STORE_HPP
#define FINALPROJECT_STORE_HPP
#include "Space.hpp"

class Store {
private:
    Space ***storeArrPtr;   //points to 2d array of Space*
    bool adjSpaces[4];      //holds whether adjacent spaces are valid to move to or not
    int numRows;
    int numCols;
    const int EDGES = 2;
    Player *player1;
public:
    Store();
    void printStore();
    void getAdjSpaces(int r, int c);    //adds adjacent space evaluations to adjSpaces array
    void movePlayer();
    void interactFoodAisle();
    void interactCoffee();
    void interactFamily();
    void interactSP();

    //get and set methods
    void setPlayer(Player*);
    Player* getPlayer();
    bool getAdjSpaces();
    void setNumRows(int nRows);
    int getNumRows();
    void setNumCols(int nCols);
    int getNumCols();
    ~Store();
};


#endif //FINALPROJECT_STORE_HPP
