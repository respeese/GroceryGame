/*************************************************************************************
 * Program Name: Player.cpp
 * Date: 6/10/19
 * Description: This is the Player class implementation file. The Player class
 * represents the user in a grocery store. This file defines the methods for the
 * Player class.
 **************************************************************************************/

#include "Player.hpp"
#include <iostream>
using std::cout;
using std::endl;


/************************************************************************************
Name: 		Player
Calls:      none
Passed: 	nothing
Returns: 	none

Constructor for Player object. Sets energy, row, col, and dead variables.
************************************************************************************/
Player::Player() {
    energy = 20;
    row = 3;
    col = 1;
    dead = false;
}


/************************************************************************************
Name: 		Player
Calls:      none
Passed: 	2 ints
Returns: 	none

Constructor for Player object. Sets energy, row, col, and dead variables. Uses 2 int
 parameters to place player in store.
************************************************************************************/
Player::Player(int r, int c) {
    energy = 20;
    row = r;
    col = c; //player starts in bottom left corner
    dead = false;
}



/************************************************************************************
Name: 		move
Calls:      none
Passed:     int
Returns: 	void

Moves player by updated row or col variables. Prints corresponding message.
************************************************************************************/
void Player::move(int direction) {
    switch(direction) {
        //move up
        case 0:
            row -= 1;
            cout << "You have moved up\n" << endl;
            break;
        //move right
        case 1:
            col += 1;
            cout << "You have moved right\n" << endl;
            break;
        //move down
        case 2:
            row += 1;
            cout << "You have moved down\n" << endl;
            break;
        //move left
        case 3:
            col -= 1;
            cout << "You have moved left\n" << endl;
            break;
    }
}



/************************************************************************************
Name: 		addBasket
Calls:      addItem, getLengthItems
Passed:     foodItem
Returns: 	void

Adds passed food item to basket. Prints corresponding message.
************************************************************************************/
void Player::addBasket(foodItem item) {
    if(basket.getLengthItems() < 15) {
        switch (item) {
            case 0:
                cout << "empty ";
                break;
            case 1:
                cout << "You grab a meat item and put it in your basket." << endl;
                break;
            case 2:
                cout << "You grab a carb item and put it in your basket." << endl;
                break;
            case 3:
                cout << "You grab a vegetable item and put it in your basket." << endl;
                break;
            case 4:
                cout << "You grab a drink item and put it in your basket." << endl;
                break;
            case 5:
                cout << "coffee ";
                break;
        }

        basket.addItem(item);
    }
    else {
        cout << "Your basket is full." << endl;
    }
}



/************************************************************************************
Name: 		removeBasket
Calls:      removeItem, getLengthItems
Passed:     foodItem
Returns: 	void

Removes passed food item from basket. Prints corresponding message.
************************************************************************************/
void Player::removeBasket(foodItem item) {
    if(basket.getLengthItems() > 0) {
        switch (item) {
            case 0:
                cout << "empty ";
                break;
            case 1:
                cout << "You try to return a meat item to the shelf." << endl;
                break;
            case 2:
                cout << "You try to return a carb item to the shelf." << endl;
                break;
            case 3:
                cout << "You try to return a vegetable item to the shelf." << endl;
                break;
            case 4:
                cout << "You try to return a drink item to the shelf." << endl;
                break;
            case 5:
                cout << "coffee ";
                break;
        }
        basket.removeItem(item);
    }
    else {
        cout << "Your basket is empty." << endl;
    }
}


/************************************************************************************
Name: 		printBasket
Calls:      printItems, getLengthItems
Passed:     nothing
Returns: 	void

Checks that basket has items then prints them.
************************************************************************************/
void Player::printBasket() {
    if(basket.getLengthItems() > 0) {
        cout << "\nHere are the items in your basket:" << endl;
        basket.printItems();
    }
    else {
        cout << "\nYour basket is empty." << endl;
    }
}


/************************************************************************************
Name: 		printBasketSize
Calls:      getLengthItems
Passed:     nothing
Returns: 	void

Prints number of items in basket
************************************************************************************/
void Player::printBasketSize() {
    cout << "\nYou have " << basket.getLengthItems() << " items in your basket." << endl;
}

//gets basket
GroceryList Player::getBasket() {
    return basket;
}

//sets basket
void Player::setBasket(GroceryList b) {
    basket = b;
}

//gets player's energy
int Player::getEnergy() {
    return energy;
}

//sets energy
void Player::setEnergy(int energy) {
    this->energy = energy;
}

//gets player's row
int Player::getRow() {
    return row;
}

//gets player's column
int Player::getCol() {
    return col;
}

//sets player's row
void Player::setRow(int r) {
    row = r;
}

//sets player's column
void Player::setCol(int c) {
    col = c;
}

//sets dead bool variable
void Player::setDead(bool status) {
    dead = status;
}

//gets if player is dead or not
bool Player::getDead() {
    if(energy <= 0) {
        dead = true;
    }
    return dead;
}