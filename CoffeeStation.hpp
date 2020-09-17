/*************************************************************************************
 * Program Name: CoffeeStation.hpp
 * Date: 6/10/19
 * Description: This is the CoffeeStation class specification file. The CoffeeStation class
 * represents a space with free coffee in a grocery store. This is a derived class of
 * the Space class. This file declares the class data members and methods.
 **************************************************************************************/

#ifndef FINALPROJECT_COFFEESTATION_HPP
#define FINALPROJECT_COFFEESTATION_HPP
#include "Space.hpp"
#include <string>

class CoffeeStation : public Space {
private:
    int numCoffees;
public:
    CoffeeStation();
    CoffeeStation(Space*, Space*);
    void useCoffee();
    std::string getSpaceType();
};


#endif //FINALPROJECT_COFFEESTATION_HPP
