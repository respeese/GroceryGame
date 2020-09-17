/*************************************************************************************
 * Program Name: GroceryList.hpp
 * Date: 6/10/19
 * Description: This is the GroceryList class specification file. The GroceryList class
 * represents a space with a sales person in a grocery store. This file declares the
 * class data members and methods.
 **************************************************************************************/

#ifndef FINALPROJECT_GROCERYLIST_HPP
#define FINALPROJECT_GROCERYLIST_HPP
#include "foodItemType.hpp"
#include <map>
#include <vector>

class GroceryList {
private:
    std::vector<foodItem>basket;
public:
    void addItem(foodItem item);
    void removeItem(foodItem item);
    void printItems();
    int getLengthItems();
    int getNumCarbs();
    int getNumMeat();
    int getNumVeggies();
    int getNumDrinks();
    bool checkListComplete();
    std::vector<foodItem> getBasket();
    void setBasket(std::vector<foodItem>);
};


#endif //FINALPROJECT_GROCERYLIST_HPP
