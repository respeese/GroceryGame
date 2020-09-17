/*************************************************************************************
 * Program Name: GroceryList.cpp
 * Date: 6/10/19
 * Description: This is the GroceryList class implementation file. The GroceryList class
 * represents a basket with items from a list. This file defines the methods for the
 * GroceryList class.
 **************************************************************************************/

#include "GroceryList.hpp"
#include <iostream>
using std::cout;
using std::endl;


/************************************************************************************
Name: 		addItem
Calls:      size,push_back
Passed: 	foodItem
Returns: 	void

Adds item to vector. Checks to make sure size does not exceed 15.
************************************************************************************/
void GroceryList::addItem(foodItem item) {
    if(basket.size() < 15) {
        basket.push_back(item);
    }
    else {
        cout << "Your basket is full" << endl;
    }
}


/************************************************************************************
Name: 		removeItem
Calls:      size, erase, empty
Passed: 	foodItem
Returns: 	void

Removes item from vector. Checks to make sure vector is not empty.
************************************************************************************/
void GroceryList::removeItem(foodItem item) {
    int itemsRemoved = 0;

    if(!basket.empty()) {
        for(int i = 0; i < basket.size(); i++) {
            if(basket[i] == item) {
                if(itemsRemoved < 1) {
                    basket.erase(basket.begin() + i);
                    itemsRemoved += 1;
                }
            }
        }
        if(itemsRemoved == 0) {
            cout << "That item is not in your basket." << endl;
        }
    }
}



/************************************************************************************
Name: 		printItems
Calls:      size
Passed: 	nothing
Returns: 	void

Prints items in vector
************************************************************************************/
void GroceryList::printItems() {
    for(int i = 0; i < basket.size(); i++) {
        switch(basket[i]) {
            case 0:
                cout << "empty ";
                break;
            case 1:
                cout << (i+1) << ": " << "meat item" << endl;
                break;
            case 2:
                cout << (i+1) << ": " << "carb item" << endl;
                break;
            case 3:
                cout << (i+1) << ": " << "vegetable item" << endl;
                break;
            case 4:
                cout << (i+1) << ": " << "drink item" << endl;
                break;
            case 5:
                cout << "coffee ";
                break;
        }
    }
}

//returns vector size
int GroceryList::getLengthItems() {
    return basket.size();
}


/************************************************************************************
Name: 		getNumCarbs
Calls:      size, empty
Passed: 	nothing
Returns: 	int

Returns number of carbs in vector. Checks if vector is empty.
************************************************************************************/
int GroceryList::getNumCarbs() {
    int numCarbs = 0;

    if(!basket.empty()) {
        for (int i = 0; i < basket.size(); i++) {
            if (basket[i] == carb) {
                numCarbs += 1;
            }
        }
    }
    return numCarbs;
}


/************************************************************************************
Name: 		getNumMeat
Calls:      size, empty
Passed: 	nothing
Returns: 	int

Returns number of meat items in vector. Checks if vector is empty.
************************************************************************************/
int GroceryList::getNumMeat() {
    int numMeat = 0;

    if(!basket.empty()) {
        for (int i = 0; i < basket.size(); i++) {
            if (basket[i] == meat) {
                numMeat += 1;
            }
        }
    }

    return numMeat;
}


/************************************************************************************
Name: 		getNumDrinks
Calls:      size, empty
Passed: 	nothing
Returns: 	int

Returns number of drinks in vector. Checks if vector is empty.
************************************************************************************/
int GroceryList::getNumDrinks() {
    int numDrinks = 0;

    if(!basket.empty()) {
        for (int i = 0; i < basket.size(); i++) {
            if (basket[i] == drink) {
                numDrinks += 1;
            }
        }
    }

    return numDrinks;
}


/************************************************************************************
Name: 		getNumVeggies
Calls:      size, empty
Passed: 	nothing
Returns: 	int

Returns number of vegetables in vector. Checks if vector is empty.
************************************************************************************/
int GroceryList::getNumVeggies() {
    int numVeggies = 0;

    if(!basket.empty()) {
        for (int i = 0; i < basket.size(); i++) {
            if (basket[i] == vegetable) {
                numVeggies += 1;
            }
        }
    }

    return numVeggies;
}


/************************************************************************************
Name: 		checkListComplete
Calls:      nothing
Passed: 	nothing
Returns: 	bool

Checks if vector has items from grocery list and return true if it does and false if
 it does not.
************************************************************************************/
bool GroceryList::checkListComplete() {
    bool carbCheck = false, meatCheck = false, drinkCheck = false, veggieCheck = false, completeList = false;

    //see if enough of each food type was picked up by player
    if(getNumCarbs() == 4) {
        cout << "You have enough carbs for the dinner party." << endl;
        carbCheck = true;
    }
    if(getNumVeggies() == 3) {
        cout << "You have enough vegetables for the dinner party." << endl;
        veggieCheck = true;
    }
    if(getNumDrinks() == 3) {
        cout << "You have enough drinks for the dinner party." << endl;
        drinkCheck = true;
    }
    if(getNumMeat() == 2) {
        cout << "You have enough meat for the dinner party." << endl;
        meatCheck = true;
    }

    //check if list is complete
    if(carbCheck && veggieCheck && drinkCheck && meatCheck) {
        completeList = true;
    }

    return completeList;
}

//get basket
std::vector<foodItem> GroceryList::getBasket() {
    return basket;
}

//sets basket
void GroceryList::setBasket(std::vector<foodItem> b) {
    basket = b;
}