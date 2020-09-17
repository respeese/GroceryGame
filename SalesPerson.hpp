/*************************************************************************************
 * Program Name: SalesPerson.hpp
 * Date: 6/10/19
 * Description: This is the SalesPerson class specification file. The SalesPerson class
 * represents a space with a sales person in a grocery store. This is a derived class of
 * the Space class. This file declares the class data members and methods.
 **************************************************************************************/

#ifndef FINALPROJECT_SALESPERSON_HPP
#define FINALPROJECT_SALESPERSON_HPP
#include "Space.hpp"

class SalesPerson : public Space {
private:
public:
    SalesPerson();
    SalesPerson(Space *t, Space *l);
    std::string getSpaceType();
    void sell();
};


#endif //FINALPROJECT_SALESPERSON_HPP
