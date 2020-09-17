/*************************************************************************************
 * Program Name: Aisle.cpp
 * Date: 6/2/19
 * Description: This is the Aisle class implementation file. The Aisle class represents
 * an aisle in a grocery store. This is a derived class of the Space class.
 * This file defines the methods for the Aisle class.
 **************************************************************************************/

#include "Aisle.hpp"
#include <iostream>
using std::cout;


/************************************************************************************
Name: 		Aisle
Calls:      none
Passed: 	nothing
Returns: 	none

Constructor for Aisle object.
************************************************************************************/
Aisle::Aisle() : Space(){
}


/************************************************************************************
Name: 		Aisle - custom
Calls:      none
Passed: 	4 Space*, foodItem
Returns: 	none

Constructor for Aisle object using 4 Space* and foodItem parameters.
************************************************************************************/
Aisle::Aisle(Space *t, Space *r, Space *b, Space *l, foodItem i) : Space(t, r, b, l, i){
}



//returns the type of Space object based on type of item
std::string Aisle::getSpaceType() {
    switch(item) {
        case 0:
            return "empty aisle";
        case 1:
            return "meat aisle";
        case 2:
            return "carb aisle";
        case 3:
            return "vegetable aisle";
        case 4:
            return "drinks aisle";
        case 5:
            return "coffee station";
    }
}