/*************************************************************************************
 * Program Name: Simulation.hpp
 * Date: 6/2/19
 * Description: This is the Simulation class specification file. The Simulation class
 * represents a simulation of the game. This file declares the class data members and
 * methods.
 **************************************************************************************/

#ifndef FINALPROJECT_MENU_HPP
#define FINALPROJECT_MENU_HPP


class Simulation {
private:
    int playChoice;
    int steps;
public:
    Simulation();
    void playMenu();
    void printGroceryList();
    void simulate();
    //get and set methods
    int getPlayChoice();
    void setPlayChoice(int pc);
    int getSteps();
    void setSteps(int s);
};


#endif //FINALPROJECT_MENU_HPP
