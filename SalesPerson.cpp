/*************************************************************************************
 * Program Name: SalesPerson.cpp
 * Date: 6/10/19
 * Description: This is the SalesPerson class implementation file. The SalesPerson class
 * represents a space with a sales person in a grocery store. This is a derived class of
 * the Space class. This file defines the methods for the SalesPerson class.
 **************************************************************************************/

#include "SalesPerson.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/************************************************************************************
Name: 		SalesPerson
Calls:      none
Passed: 	nothing
Returns: 	none

Constructor for SalesPerson object.
************************************************************************************/
SalesPerson::SalesPerson() : Space() {
}


/************************************************************************************
Name: 		SalesPerson - custom
Calls:      none
Passed: 	2 Space*
Returns: 	none

Constructor for SalesPerson object using 2 Space* parameters.
************************************************************************************/
SalesPerson::SalesPerson(Space *t, Space *l) : Space(t, nullptr, nullptr, l, empty){
}


/************************************************************************************
Name: 		sell
Calls:      addBasket, setEnergy, getEnergy
Passed: 	nothing
Returns: 	void

Generates random food item and adds it to player's basket. Decreases player's energy
 by 3.
************************************************************************************/
void SalesPerson::sell() {
    foodItem randItem;

    //give space random item
    int foodType = rand() % 4 + 1;

    //assign item to random type of food: meat, cheese, carb, fruit, vegetable, or liquor
    randItem = static_cast<foodItem>(foodType);

    cout << "\nA sales person tries to sell you something random...and they're really bad at it."
            "\nHaving to endure that awkward sales pitch depletes your energy by 3 points and you walk "
            "\naway with a random food item in your basket." << endl;
    player->addBasket(randItem);
    player->setEnergy(player->getEnergy() - 3);

}


//returns the type of Space object
std::string SalesPerson::getSpaceType() {
    return "sales person";
}