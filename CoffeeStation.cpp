/*************************************************************************************
 * Program Name: CoffeeStation.cpp
 * Date: 6/10/19
 * Description: This is the CoffeeStation class implementation file. The CoffeeStation class
 * represents a space with free coffee in a grocery store. This is a derived class of
 * the Space class. This file defines the methods for the CoffeeStation class.
 **************************************************************************************/

#include "CoffeeStation.hpp"
#include "inputVal.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


/************************************************************************************
Name: 		CoffeeStation
Calls:      none
Passed: 	nothing
Returns: 	none

Constructor for CoffeeStation object. Sets numCoffees.
************************************************************************************/
CoffeeStation::CoffeeStation() : Space(nullptr, nullptr, nullptr, nullptr, coffee){
    numCoffees = 2;
}


/************************************************************************************
Name: 		CoffeeStation - custom
Calls:      none
Passed: 	2 Space*
Returns: 	none

Constructor for CoffeeStation object. Sets numCoffees.
************************************************************************************/
CoffeeStation::CoffeeStation(Space *r, Space *b) : Space(nullptr, r, b, nullptr, coffee) {
    numCoffees = 2;
}


/************************************************************************************
Name: 		useCoffee
Calls:      getPosInt, setEnergy, getEnergy
Passed: 	nothing
Returns: 	none

//Simulates the player using a coffee form the station. Subtracts 1 from numCoffees unless there
//are no more left. Prints message describing either situation.
 ************************************************************************************/
void CoffeeStation::useCoffee() {
    int choice = 0;

    //prompt user to use coffee
    if (numCoffees > 0) {
        cout << "Would you like to use a coffee? It will boost your energy by 2 points."
                "\n1. Use coffee"
                "\n2. Don't use it" << endl;
        cout << "Choice: ";
        choice = getPosInt();

        while(choice != 1 && choice != 2) {
            cout << "Incorrect Input: Select one of menu options 1 or 2." << endl;
            cout << "Would you like to use a coffee?"
                    "\n1. Use coffee"
                    "\n2. Don't use" << endl;
            cout << "Choice: ";
            choice = getPosInt();
        }

        //simulate using coffee
        if(choice == 1) {
            numCoffees--;
            player->setEnergy(player->getEnergy() + 2);
            cout << "You have used a coffee. You immediately feel the caffeine coursing through your veins."
                    "\nYour energy has increased by 2 points. Hooray!" << endl;
            cout << "There are " << numCoffees << " coffees left." << endl;
        }
    }
    else {
        cout << "Uh oh. There are no more coffees available. That sucks." << endl;
    }
}


//returns the type of space
std::string CoffeeStation::getSpaceType() {
    return "coffee station";
}