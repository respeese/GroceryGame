/*************************************************************************************
 * Program Name: Simulation.cpp
 * Date: 6/11/19
 * Description: This is the Simulation class implementation file. The Simulation class
 * represents a Grocery Shopper game. This file defines the methods for the Simulation
 * class.
 **************************************************************************************/
#include "Store.hpp"
#include "Player.hpp"
#include "Simulation.hpp"
#include "inputVal.hpp"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


/************************************************************************************
Name: 		simulation
Calls:      none
Passed: 	nothing
Returns: 	none

Constructor for Simulation. Sets playChoice and steps.
************************************************************************************/
Simulation::Simulation() {
    playChoice = 0;
    steps = 50;
}



/************************************************************************************
Name: 		playMenu
Calls:      getPosInt
Passed: 	nothing
Returns: 	void

Prompts user to play or quit game. Validates choice.
************************************************************************************/
void Simulation::playMenu() {
    cout << "Would you like to play the game?"
            "\n1. Play"
            "\n2. Quit" << endl;
    cout << "Choice: ";
    playChoice = getPosInt();

    while(playChoice != 1 && playChoice != 2) {
        cout << "Incorrect Input: Select one of menu options 1 or 2." << endl;
        cout << "Would you like to play the game?"
                "\n1. Play"
                "\n2. Quit" << endl;
        cout << "Choice: ";
        playChoice = getPosInt();
    }
}


/************************************************************************************
Name: 		printGroceryList
Calls:      nothing
Passed: 	nothing
Returns: 	void

Prints the grocery list
************************************************************************************/
void Simulation::printGroceryList() {
    cout << "\nGrocery list:"
            "\n3 drinks"
            "\n2 meats"
            "\n4 carbs"
            "\n3 vegetables\n" << endl;
}


/************************************************************************************
Name: 		simulate
Calls:      Store, playMenu, printGroceryList, printStore, movePlayer, interactSP,
            interactFamily, interactCoffee, interactFoodAisle
Passed: 	nothing
Returns: 	void

Runs simulation of game by creating store object and calling store methods. Repeats
 methods for amount of steps. Determines if user won or lost. Repeats game if user
 wants.
************************************************************************************/
void Simulation::simulate() {
    Store store1;

    playMenu();

    while(playChoice == 1) {
        printGroceryList();
        store1.printStore();
        cout << endl;

        do {
            cout << "*** Steps left: " << steps << " ***" << endl;
            store1.movePlayer();
            store1.printStore();
            printGroceryList();
            store1.interactSP();
            store1.interactFamily();
            store1.interactCoffee();
            store1.interactFoodAisle();
            store1.getPlayer()->printBasket();
            cout << "\nYour energy: " << store1.getPlayer()->getEnergy() << endl << endl;
            steps -= 1;
        } while (!store1.getPlayer()->getDead() && (steps > 0) && !store1.getPlayer()->getBasket().checkListComplete());

        if(store1.getPlayer()->getDead()) {
            cout << "Oh shoot! You ran out of energy!\n" << endl;
        }
        else if(steps <= 0) {
            cout << "Sorry, you ran out of moves. :(\n" << endl;
        }
        else {
            cout << "WOOO! You found all the items on the list! Now, you are sure to have an awesome dinner party." << endl;
        }
        cout << "You can play again if you like." <<endl;
        playMenu();
    }
}

//gets playChoice
int Simulation::getPlayChoice() {
    return playChoice;
};

//sets playChoice
void Simulation::setPlayChoice(int pc) {
    playChoice = pc;
};

//gets number of steps
int Simulation::getSteps() {
    return steps;
};

//sets number of steps
void Simulation::setSteps(int s) {
    steps = s;
};