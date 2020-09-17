/*************************************************************************************
 * Program Name: Space.cpp
 * Date: 6/2/19
 * Description: This is the Space class implementation file. The Space class represents
 * a space on a Map. This file defines the methods for the Space class.
 **************************************************************************************/

#include "Space.hpp"

/************************************************************************************
Name: 		Space
Calls:      nothing
Passed: 	nothing
Returns: 	none

Constructor to create Space object. Sets top, bottom, right, left, and player pointers.
 Sets food item to empty.
************************************************************************************/
Space::Space() {
    top = nullptr;
    bottom = nullptr;
    right = nullptr;
    left = nullptr;
    player = nullptr;
    item = empty;
}


/************************************************************************************
Name: 		Space - custom
Calls:      nothing
Passed: 	4 Space*, foodItem
Returns: 	none

Takes in 4 Space pointers and creates Space object. Sets top, bottom, right, left, and
 player pointers.
 Sets food item to passed foodItem.
************************************************************************************/
Space::Space(Space *t, Space *r, Space *b, Space *l, foodItem i) {
    top = t;
    bottom = b;
    right = r;
    left = l;
    player = nullptr;
    item = i;
}

//gets item at Space
foodItem Space::getItem() {
    return item;
}

//sets item
void Space::setItem(foodItem item) {
    this->item = item;
}

//get top pointer
Space* Space::getTop() {
    return top;
}

//get bottom pointer
Space* Space::getBottom() {
    return bottom;
}

//get left pointer
Space* Space::getLeft() {
    return left;
}

//get right pointer
Space* Space::getRight() {
    return right;
}

//get Player pointer
Player* Space::getPlayer() {
    return player;
}

//sets top pointer
void Space::setTop(Space *t) {
    top = t;
}

//sets bottom pointer
void Space::setBottom(Space *b) {
    bottom = b;
}

//sets left pointer
void Space::setLeft(Space *l) {
    left = l;
}

//sets right pointer
void Space::setRight(Space *r) {
    right = r;
}

//sets Player pointer
void Space::setPlayer(Player *p) {
    player = p;
}


/************************************************************************************
Name: 		setDirections
Calls:      nothing
Passed: 	4 Space*
Returns: 	void

Sets the 4 direction Space pointers to passed in Space pointers.
************************************************************************************/
void Space::setDirections(Space *t, Space *r, Space *b, Space *l) {
    top = t;
    right = r;
    bottom = b;
    left = l;
}