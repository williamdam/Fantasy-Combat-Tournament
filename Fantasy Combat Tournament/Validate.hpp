/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Validate.hpp is the specification file for the 
** input validation functions, contained in a separate implementation 
** file.
*********************************************************************/
#ifndef Validate_hpp
#define Validate_hpp
#include <string>

// Function prototypes.  Defined in separate implementation file.

// Input validation for integer
bool validateInteger(std::string& incomingString, int, int);

// Validate string input and spit usable integer
int integerInput(int w, int h);

#endif