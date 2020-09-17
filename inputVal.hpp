/*******************************************************************************
** Program name: Final Project
** Author:       Ryan Speese
** Date:         6/10/19
** Description: inputVal.hpp is the class specification file for the
        *              input validation functions It has the prototypes for the isInRange,
        *              isPosInt, and getPosInt functions.
*******************************************************************************/

#ifndef FINALPROJECT_INPUTVAL_HPP
#define FINALPROJECT_INPUTVAL_HPP
#include <string>

bool isInRange(int, int, int);
bool isPosInt(std::string);
int getPosInt();
#endif //FINALPROJECT_INPUTVAL_HPP
