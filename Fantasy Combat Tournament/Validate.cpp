/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Validate.cpp is the implementation file, which contains
** input validation functions.  
*********************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "Validate.hpp"

/*********************************************************************
** Description: Input validation function receives string, checks to
** see if it each character is an integer, then returns bool.
** Range limits passed as arguments.
*********************************************************************/
bool validateInteger(std::string& incomingString, int low, int high) {
	bool isInteger = 0;						// Bool value to return
	int errorCount = 0;						// Error counter
	int count = incomingString.length();	// Set count to string length

	// Prevent users from pressing enter without input
	if (incomingString == "") {
		errorCount++;
	}

	// Step through character array to look for non-digit characters
	for (int i = 0; i < count; i++) {

		// If first character is negative sign, don't count error
		if (i == 0 && incomingString[i] == '-') {
			errorCount;
		}
		// If character is not digit or is decimal
		else if (!(isdigit(incomingString[i])) || incomingString[i] == '.' || incomingString[i] == ' ') {
			errorCount++;	// Increment error counter
		}
	}

	// If no errors found...
	if (errorCount == 0) {
		// Convert input to integer
		int convertedInteger;
		convertedInteger = stoi(incomingString);

		// Check integer for range violation
		if (convertedInteger < low || convertedInteger > high) {
			isInteger = 0;	// Bool false
		}
		else {
			isInteger = 1;	// Bool true
		}
	}

	else if (errorCount > 0) {
		isInteger = 0;	// Bool false
	}

	return isInteger;	// Return bool
}

/*********************************************************************
** Description: int function integerInput(int n) prompts user for
** input from 1 to ceiling.  Ceiling controlled by argument passed
** to function. Input validation with limits set, using validateInteger().
** Function returns integer value of validated user input.
*********************************************************************/
int integerInput(int w, int h) {
	bool isInteger = 0;					// Set bool to false for input validation
	std::string inputOption;			// Declare string for input

	while (isInteger == 0) {			// Begin input validation loop
		// NO MESSAGE PROMPT
		std::getline(std::cin, inputOption);
		isInteger = validateInteger(inputOption, w, h);	// Validate input

		if (isInteger == 0) {			// Fail validation and restart looop
			std::cout << "Invalid entry! You must enter a number " << w << " - " << h << std::endl;
		}
	}
	int option;
	option = stoi(inputOption);			// Set integer value

	return option;						// Return integer
}
