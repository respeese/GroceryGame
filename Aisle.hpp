/*************************************************************************************
 * Program Name: Aisle.hpp
 * Date: 6/2/19
 * Description: This is the Aisle class specification file. The Aisle class represents
 * an aisle in a grocery store. This is a derived class of the Space class.
 * This file declares the class data members and methods.
 **************************************************************************************/

#ifndef FINALPROJECT_AISLE_HPP
#define FINALPROJECT_AISLE_HPP
#include "Space.hpp"

class Aisle : public Space {
public:
    Aisle();
    Aisle(Space *t, Space *r, Space *b, Space *l, foodItem i);
    std::string getSpaceType();
};


#endif //FINALPROJECT_AISLE_HPP
