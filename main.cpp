/*******************************************************************************
** Program name: Final Project
** Author:       Ryan Speese
** Date:         6/11/19
** Description: This is the main function for the Grocery Shopper Game. In the game,
 * the user moves throughout a store and gather items from their grocery list.
 * They win if they can get all the items from the list without running out of
 * energy or steps.
*******************************************************************************/
#include <iostream>
#include "foodItemType.hpp"
#include "Store.hpp"
#include "Player.hpp"
#include "Simulation.hpp"
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;

int main() {
    srand(time(0));
    Simulation game;

    cout << "Welcome to the Grocery Shopper Game!"
            "\n\nYou are throwing a dinner party in a few hours and you're in a rush to get the ingredients. The goal of"
            "\nthe game is to move throughout the grocery store and get all the items on your list before you run out of"
            "\nmoves or energy. You start with 50 moves and 20 energy points."
            "\nAlong the way, you'll encounter cumbersome obstacles that deplete your energy and potentially derail "
            "\nyou from your goal. "
            "\n\nHere is a list of what you'll encounter:"
            "\n- Food aisles: You can pick up or put back a food item"
            "\n- Coffee stations: You will get an energy boost form the caffeine"
            "\n- A sales person: They will drain your energy and give you a random item"
            "\n- A family: They will drain your energy significantly"
            "\n\nWill you be able to get all the items on your list and have a successful dinner party? "
            "\nOnly time will tell...\n" << endl;
    game.simulate();

    return 0;
}
