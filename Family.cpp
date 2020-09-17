/*************************************************************************************
 * Program Name: Family.cpp
 * Date: 6/10/19
 * Description: This is the Family class implementation file. The Family class
 * represents a space with a family in a grocery store. This is a derived class of
 * the Space class. This file defines the methods for the Family class.
 **************************************************************************************/

#include "Family.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


/************************************************************************************
Name: 		Family
Calls:      none
Passed: 	nothing
Returns: 	none

Constructor for Family object.
************************************************************************************/
Family::Family() : Space(){
}


/************************************************************************************
Name: 		Family - custom
Calls:      none
Passed: 	4 Space*
Returns: 	none

Constructor for Family object using 4 Space* parameters.
************************************************************************************/
Family::Family(Space *t, Space *r, Space *b, Space *l) : Space(t, r, b, l, empty) {
}


/************************************************************************************
Name: 		annoy
Calls:      getDead, setEnergy, getEnergy
Passed: 	nothing
Returns: 	void

Checks if player is alive then subtracts 5 energy points from them.
************************************************************************************/
void Family::annoy() {
    //if player is not dead, subtract energy from them
    if(!player->getDead()) {
        player->setEnergy(player->getEnergy() - 5);
        cout << "Oh no...there's a family of 8 in the aisle. You try to maneuver around the stressed parents yelling"
                "\nat their 6 kids who are throwing tantrums. How exhausting!"
                "\nYour energy has decreased by 5." << endl;
    }
    else {
        cout << "Sorry, you have run out of energy." << endl;
    }
}


//returns the type of Space object
std::string Family::getSpaceType() {
    return "family";
}