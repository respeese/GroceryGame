/*************************************************************************************
 * Program Name: Store.cpp
 * Date: 6/11/19
 * Description: This is the Store class implementation file. The Store class
 * represents a grocery store. This file defines the methods for the Store class.
 **************************************************************************************/

#include "Store.hpp"
#include "CoffeeStation.hpp"
#include "Aisle.hpp"
#include "Family.hpp"
#include "SalesPerson.hpp"
#include "inputVal.hpp"
#include <iostream>
using std::cout;
using std::endl;


/************************************************************************************
Name: 		Store
Calls:      none
Passed: 	nothing
Returns: 	none

Constructor for Store. Creates 2d array for store. Assigns spaces to correct Space
 types. Creates and places player object.
************************************************************************************/
Store::Store() {
    numRows = 3 + EDGES;
    numCols = 4 + EDGES;
    for(int i = 0; i < 4; i++) {
        adjSpaces[i] = false;
    }

    //create 2d array
    storeArrPtr = new Space**[numRows]; //allocate rows
    for(int row = 0; row < numRows; row++) {
        storeArrPtr[row] = new Space*[numCols]; //allocate columns
    }

    //set all spaces to null for now
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            storeArrPtr[i][j] = nullptr;
        }
    }

    //assign spaces to specific types
    storeArrPtr[1][1] = new CoffeeStation();
    storeArrPtr[1][2] = new Aisle();
    storeArrPtr[1][3] = new Family();
    storeArrPtr[1][4] = new CoffeeStation();
    storeArrPtr[2][1] = new Aisle();
    storeArrPtr[2][2] = new Aisle();
    storeArrPtr[2][3] = new Aisle();
    storeArrPtr[2][4] = new Aisle();
    storeArrPtr[3][1] = new Aisle();
    storeArrPtr[3][2] = new Family();
    storeArrPtr[3][3] = new Aisle();
    storeArrPtr[3][4] = new SalesPerson();

    //create linked structure by assigning direction pointers
    //Note: aisles with food items are bordered on left and right by a boundary, like in a real store, and therefore
    //      player cannot move left or right from these spaces
    storeArrPtr[1][1]->setDirections(nullptr, storeArrPtr[1][2], storeArrPtr[2][1], nullptr);
    storeArrPtr[1][2]->setDirections(nullptr, storeArrPtr[1][3], storeArrPtr[2][2], storeArrPtr[1][1]);
    storeArrPtr[1][3]->setDirections(nullptr, storeArrPtr[1][4], storeArrPtr[2][3], storeArrPtr[1][2]);
    storeArrPtr[1][4]->setDirections(nullptr, nullptr, storeArrPtr[2][4], storeArrPtr[1][3]);
    storeArrPtr[2][1]->setDirections(storeArrPtr[1][1], nullptr, storeArrPtr[3][1], nullptr);
    storeArrPtr[2][2]->setDirections(storeArrPtr[1][2], nullptr, storeArrPtr[3][2], nullptr);
    storeArrPtr[2][3]->setDirections(storeArrPtr[1][3], nullptr, storeArrPtr[3][3], nullptr);
    storeArrPtr[2][4]->setDirections(storeArrPtr[1][4], nullptr, storeArrPtr[3][4], nullptr);
    storeArrPtr[3][1]->setDirections(storeArrPtr[2][1], storeArrPtr[3][2], nullptr, nullptr);
    storeArrPtr[3][2]->setDirections(storeArrPtr[2][2], storeArrPtr[3][3], nullptr, storeArrPtr[3][1]);
    storeArrPtr[3][3]->setDirections(storeArrPtr[2][3], storeArrPtr[3][4], nullptr, storeArrPtr[3][2]);
    storeArrPtr[3][4]->setDirections(storeArrPtr[2][4], nullptr, nullptr, storeArrPtr[3][3]);

    //set aisle spaces for food
    storeArrPtr[2][1]->setItem(vegetable);
    storeArrPtr[2][2]->setItem(carb);
    storeArrPtr[2][3]->setItem(drink);
    storeArrPtr[2][4]->setItem(meat);

    //place Player in bottom-left corner of store
    player1 = new Player(3, 1);
    storeArrPtr[3][1]->setPlayer(player1);
}



/************************************************************************************
Name: 		printStore
Calls:      getPlayer
Passed: 	nothing
Returns: 	void

Displays the store in current state with player object and border.
************************************************************************************/
void Store::printStore() {
    cout << "~~ Store Map ~~" << endl;

    for(int row = 0; row < numRows; row++) {
        cout << endl;
        for(int col = 0; col < numCols; col++) {
            //display top and bottom edges
            if (row == 0 || row == (numRows - 1)) {
                cout << "-";
            }
            //display side edges
            else if(col == 0 || col == (numCols - 1)) {
                cout << "|";
            }
            //print player
            else if(storeArrPtr[row][col]->getPlayer() != nullptr) {
                cout << 'P';
            }
            //fill in rest of spaces with blanks
            else if(row > 0 && row < numRows && col > 0 && col < numCols &&
            storeArrPtr[row][col]->getPlayer() == nullptr) {
                cout << " ";
            }
        }
    }
    cout << endl;
}



/************************************************************************************
Name: 		getAdjSpaces
Calls:      getTop, getRight, getBottom, getLeft
Passed: 	int, int
Returns: 	void

//Takes in 2 ints for the row and column of a position in the store. It determines
//which directions are valid spaces to move to and updates valid directions in the
//adjSpaces array
************************************************************************************/
void Store::getAdjSpaces(int r, int c) {
    //reset adjSpaces array
    for(int i = 0; i < 4; i++){
        adjSpaces[i] = false;
    }

    //add valid directions to array
    if(storeArrPtr[r][c]->getTop() != nullptr) { //up is valid direction
        adjSpaces[0] = true;
    }
    if(storeArrPtr[r][c]->getRight() != nullptr) { //right is valid direction
        adjSpaces[1] = true;
    }
    if(storeArrPtr[r][c]->getBottom() != nullptr) { //down is valid direction
        adjSpaces[2] = true;
    }
    if(storeArrPtr[r][c]->getLeft() != nullptr) { //left is valid direction
        adjSpaces[3] = true;
    }
}


/************************************************************************************
Name: 		movePlayer
Calls:      getPlayer, getAdjSpaces, getSpaceType, getPosInt, isInRange, move,
            getRow, getCol, setPlayer
Passed: 	nothing
Returns: 	void

Gives user option of where to move. Moves player object in store according to user
 input.
************************************************************************************/
void Store::movePlayer() {
    int direction = 0;
    int oldRow = 0;
    int oldCol = 0;
    int newRow = 0;
    int newCol = 0;

    cout << "\nHere are the spaces you can move to: " << endl;

    for(int r = 1; r < (numRows-1); r++) {
        for(int c = 1; c < (numCols-1); c++) {
            //if space has player
            if(storeArrPtr[r][c]->getPlayer() != nullptr) {
                oldRow = r;
                oldCol = c;
                //determine valid directions to move to
                getAdjSpaces(r, c);
                if (adjSpaces[0]) {
                    cout << "1: up - " << storeArrPtr[r - 1][c]->getSpaceType() << endl;
                }
                if (adjSpaces[1]) {
                    cout << "2: right - " << storeArrPtr[r][c + 1]->getSpaceType() << endl;
                }
                if (adjSpaces[2]) {
                    cout << "3: down - " << storeArrPtr[r + 1][c]->getSpaceType() << endl;
                }
                if (adjSpaces[3]) {
                    cout << "4: left - " << storeArrPtr[r][c - 1]->getSpaceType() << endl;
                }

                //get user choice for the space to move to
                do {
                    cout << "\nPlease pick a number and corresponding direction to move to."
                            "\nMove to: ";
                    direction = (getPosInt() - 1);
                    while (!isInRange(direction, 0, 3)) {
                        cout << "Please pick a number between 1 and 4."
                                "\nMove to";
                        direction = (getPosInt() - 1);
                    }
                } while (!adjSpaces[direction]);
            }
        }
    }

    //update player object's row and col variables
    storeArrPtr[oldRow][oldCol]->getPlayer()->move(direction);

    //move Player* to appropriate space
    newRow = storeArrPtr[oldRow][oldCol]->getPlayer()->getRow();
    newCol = storeArrPtr[oldRow][oldCol]->getPlayer()->getCol();
    storeArrPtr[newRow][newCol]->setPlayer(player1);
    storeArrPtr[oldRow][oldCol]->setPlayer(nullptr);
}


/************************************************************************************
Name: 		interactFoodAisle
Calls:      getPlayer, getItem, getPosInt, isInRange, addBasket, removeBasket
Passed: 	nothing
Returns: 	void

Prompts user to take item, put item back, or do nothing and does this action.
************************************************************************************/
void Store::interactFoodAisle() {
    int choice = 0;

    for(int r = 1; r < (numRows-1); r++) {
        for (int c = 1; c < (numCols - 1); c++) {
            //if space has player
            if (storeArrPtr[r][c]->getPlayer() != nullptr) {
                switch(storeArrPtr[r][c]->getItem()) {
                    case 0:
                        break;
                    case 1:
                        cout << "You entered the meat aisle. Would you like to take or put back any meat?" << endl;
                        cout << "1. Take meat"
                                "\n2. Put back meat"
                                "\n3. Do nothing"
                                "\nYour choice: ";
                        choice = getPosInt();
                        //validate choice
                        while(!isInRange(choice, 1, 3)) {
                            cout << "Input is out of range. Choose 1, 2, or 3." << endl;
                            cout << "Your choice: ";
                            choice = getPosInt();
                        }

                        //add item to player's basket
                        if(choice == 1) {
                            storeArrPtr[r][c]->getPlayer()->addBasket(storeArrPtr[r][c]->getItem());
                        }
                        //remove item from player's basket
                        else if(choice == 2) {
                            storeArrPtr[r][c]->getPlayer()->removeBasket(storeArrPtr[r][c]->getItem());
                        }
                        break;
                    case 2:
                        cout << "You entered the carb aisle. Would you like to take or put back any carbs?" << endl;
                        cout << "1. Take a carb"
                                "\n2. Put back a carb"
                                "\n3. Do nothing"
                                "\nYour choice: ";
                        choice = getPosInt();
                        //validate choice
                        while(!isInRange(choice, 1, 3)) {
                            cout << "Input is out of range. Choose 1, 2, or 3." << endl;
                            cout << "Your choice: ";
                            choice = getPosInt();
                        }

                        //add item to player's basket
                        if(choice == 1) {
                            storeArrPtr[r][c]->getPlayer()->addBasket(storeArrPtr[r][c]->getItem());
                        }
                            //remove item from player's basket
                        else if(choice == 2) {
                            storeArrPtr[r][c]->getPlayer()->removeBasket(storeArrPtr[r][c]->getItem());
                        }
                        break;
                    case 3:
                        cout << "You entered the vegetable aisle. Would you like to take or put back any vegetables?" << endl;
                        cout << "1. Take a vegetable"
                                "\n2. Put back a vegetable"
                                "\n3. Do nothing"
                                "\nYour choice: ";
                        choice = getPosInt();
                        //validate choice
                        while(!isInRange(choice, 1, 3)) {
                            cout << "Input is out of range. Choose 1, 2, or 3." << endl;
                            cout << "Your choice: ";
                            choice = getPosInt();
                        }

                        //add item to player's basket
                        if(choice == 1) {
                            storeArrPtr[r][c]->getPlayer()->addBasket(storeArrPtr[r][c]->getItem());
                        }
                            //remove item from player's basket
                        else if(choice == 2) {
                            storeArrPtr[r][c]->getPlayer()->removeBasket(storeArrPtr[r][c]->getItem());
                        }
                        break;
                    case 4:
                        cout << "You entered the drink aisle. Would you like to take or put back any drinks?" << endl;
                        cout << "1. Take a drink"
                                "\n2. Put back a drink"
                                "\n3. Do nothing"
                                "\nYour choice: ";
                        choice = getPosInt();
                        //validate choice
                        while(!isInRange(choice, 1, 3)) {
                            cout << "Input is out of range. Choose 1, 2, or 3." << endl;
                            cout << "Your choice: ";
                            choice = getPosInt();
                        }

                        //add item to player's basket
                        if(choice == 1) {
                            storeArrPtr[r][c]->getPlayer()->addBasket(storeArrPtr[r][c]->getItem());
                        }
                            //remove item from player's basket
                        else if(choice == 2) {
                            storeArrPtr[r][c]->getPlayer()->removeBasket(storeArrPtr[r][c]->getItem());
                        }
                        break;
                    case 5:
                        break;
                }
            }
        }
    }
};



/************************************************************************************
Name: 		interactCoffee
Calls:      getPlayer, getSpaceType, useCoffee
Passed: 	nothing
Returns: 	void

Prompts user to take coffee or not. Calls useCoffee if user wants coffee.
************************************************************************************/
void Store::interactCoffee() {
    for(int r = 1; r < (numRows-1); r++) {
        for (int c = 1; c < (numCols - 1); c++) {
            //if space has player
            if (storeArrPtr[r][c]->getPlayer() != nullptr) {
                if (storeArrPtr[r][c]->getSpaceType() == "coffee station") {
                    //use dynamic casting on necessary spaces to access derived class methods
                    CoffeeStation *coffeeSpace = dynamic_cast<CoffeeStation*>(storeArrPtr[r][c]);
                    if(!coffeeSpace) {
                        cout << "Coffee casting didn't work." << endl;
                    }
                    else {
                        coffeeSpace->useCoffee();
                    }
                }
            }
        }
    }
}


/************************************************************************************
Name: 		interactFamily
Calls:      getPlayer, getSpaceType, annoy
Passed: 	nothing
Returns: 	void

Calls annoy() from Family and affect's player's energy.
************************************************************************************/
void Store::interactFamily() {
    for(int r = 1; r < (numRows-1); r++) {
        for (int c = 1; c < (numCols - 1); c++) {
            //if space has player
            if (storeArrPtr[r][c]->getPlayer() != nullptr) {
                if(storeArrPtr[r][c]->getSpaceType() == "family") {
                    Family *familySpace = dynamic_cast<Family *>(storeArrPtr[r][c]);
                    if(!familySpace) {
                        cout << "Family casting didn't work." << endl;
                    }
                    else {
                        familySpace->annoy();
                    }
                }
            }
        }
    }
}


/************************************************************************************
Name: 		interactSP
Calls:      getPlayer, getSpaceType, sell
Passed: 	nothing
Returns: 	void

Calls sell() from SalesPerson and adds random item to player's basket and decreases
 their energy.
************************************************************************************/
void Store::interactSP() {
    for(int r = 1; r < (numRows-1); r++) {
        for (int c = 1; c < (numCols - 1); c++) {
            //if space w/ player has a salesperson
            if (storeArrPtr[r][c]->getPlayer() != nullptr) {
                if (storeArrPtr[r][c]->getSpaceType() == "sales person") {
                    SalesPerson *spSpace = dynamic_cast<SalesPerson*>(storeArrPtr[r][c]);
                    if(!spSpace) {
                        cout << "Sales person casting didn't work." << endl;
                    }
                    else {
                        spSpace->sell();
                    }
                }
            }
        }
    }
}

//gets player
Player* Store::getPlayer() {
    return player1;
}

//sets player
void Store::setPlayer(Player *p) {
    player1 = p;
}

//gets adjSpace array
bool Store::getAdjSpaces() {
    return adjSpaces;
}

//gets number of rows
int Store::getNumRows() {
    return numRows;
}

//sets number of rows
void Store::setNumRows(int nRows) {
    numRows = nRows;
}

//gets number of columns
int Store::getNumCols() {
    return numCols;
}

//sets number of columns
void Store::setNumCols(int nCols) {
    numCols = nCols;
}

/************************************************************************************
Name: 		~Store
Calls:      getPlayer
Passed: 	nothing
Returns: 	nothing

Destructor to delete player object and store (2d array).
************************************************************************************/
Store::~Store() {
    //delete player
    for(int r = 1; r < (numRows-1); r++) {
        for (int c = 1; c < (numCols - 1); c++) {
            //if space w/ player has a salesperson
            if (storeArrPtr[r][c]->getPlayer() != nullptr) {
                delete storeArrPtr[r][c]->getPlayer();
            }
        }
    }

    //delete space objects
    for(int row = 0; row < numRows; row++) {
        for(int col = 0; col < numCols;  col++) {
            delete storeArrPtr[row][col];
        }
        delete [] storeArrPtr[row];
    }
    delete [] storeArrPtr;
}