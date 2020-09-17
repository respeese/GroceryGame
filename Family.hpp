/*************************************************************************************
 * Program Name: Family.hpp
 * Date: 6/10/19
 * Description: This is the Family class specification file. The Family class
 * represents a space with a family in a grocery store. This is a derived class of
 * the Space class. This file declares the class data members and methods.
 **************************************************************************************/

#ifndef FINALPROJECT_FAMILY_HPP
#define FINALPROJECT_FAMILY_HPP
#include "Space.hpp"

class Family : public Space {
public:
    Family();
    Family(Space *t, Space *r, Space *b, Space *l);
    void annoy();
    std::string getSpaceType();
};


#endif //FINALPROJECT_FAMILY_HPP
