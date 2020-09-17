/*******************************************************************************
** Program name: Final Project
** Author:       Ryan Speese
** Date:         6/10/19
** Description: inputVal.cpp is the implementation file for the input validation
 * functions. It stores the isInRange, isPosInt, and getPosInt function
 * definitions. These functions are used to validate user input.
*******************************************************************************/
#include <string>
#include <iostream>
#include <sstream> //stringstream
using std::cout;
using std::cin;
using std::endl;
using std::string;

/************************************************************************************
Name: 		isInRange
Called by: 	menu()
Calls: 		none
Passed: 	three ints
Returns: 	bool

The function takes in a number that will be checked, then takes in a two numbers for
 the maximum and minimum. It then checks to see if the number is between the maximum
 and minimum values. It returns true if it is within the range and false is it is not.
************************************************************************************/
bool isInRange(int ans, int min, int max) {
    if (ans > max) {
        return false;
    }
    else if (ans < min) {
        return false;
    }
    else {
        return true;
    }
}


/************************************************************************************
Name: 		isPosInt
Called by: 	getPosInt
Calls: 		isDigit
Passed: 	user input
Returns: 	bool

The function takes in the users input and checks each character to see if it's a digit
 or not. Returns false if any of the characters of the input are not digits.
************************************************************************************/
bool isPosInt(string input) {

    //check if user enters nothing
    if(input == "") {
        return false;
    }

    //increments through input characters
    for (int i = 0; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            //returns false if any thing other than digit is entered
            //including a negative sign - filters out negative numbers
            return false;
        }
    }

    return true;
}


/************************************************************************************
Name: 		getPosInt
Called by: 	menu()
Calls: 		isPosInt; stringstream
Passed: 	nothing
Returns: 	int

The function gets the users input. If the user input fails the isPosInt function test,
 the user is prompted to enter the number again.
************************************************************************************/
int getPosInt() {
    string input;
    int num;

    //get the input and check to make sure it's a positive int
    do {
        getline(cin, input);
        if (!(isPosInt(input))) {
            cout << "Sorry, you need to enter a positive integer.\n"
                    "Make sure there are no characters or spaces in your answer." << endl;
        }
    } while (!(isPosInt(input)));

    //convert the string to an int
    //code below adapted from https://www.geeksforgeeks.org/converting-strings-numbers-cc/
    std::stringstream newInt(input);
    //store value into num variable
    newInt >> num;

    return num;
}


