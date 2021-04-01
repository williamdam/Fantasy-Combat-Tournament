/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Character.cpp is the class implementation file for 
** the Character base class.  Member methods are defined within.
*********************************************************************/
#include "Character.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

/*********************************************************************
** Description: Default constructor for Character class
*********************************************************************/
Character::Character() {
	srand(static_cast<unsigned int>(time(0)));	// Seed random number generator
	armor = 0;		// Initialize armor
	strength = 0;	// Initialize strength
	type = "";		// Initialize type
}

/*********************************************************************
** Description: Set function sets character type
*********************************************************************/
void Character::setType(std::string t) {
	type = t;
}

/*********************************************************************
** Description: Get function returns character type
*********************************************************************/
std::string Character::getType() {
	return type;
}

/*********************************************************************
** Description: dieRoll function generates random number and returns 
** value.  Receives 2 args for high and low, for example, 6 sided
** die would be sent as dieRoll(6, 1).
*********************************************************************/
int Character::dieRoll(int high, int low) {
	return rand() % high + low;				// Return roll value
}

/*********************************************************************
** Description: Virtual function for attack.  Defined by derived
** character class.
*********************************************************************/
int Character::launchAttack() {
	// Virtual function
	return 0;
}

/*********************************************************************
** Description: Virtual function for defense.  Defined by derived
** character class.
*********************************************************************/
int Character::launchDefense(int a) {
	// Virtual function
	return 0;
}

/*********************************************************************
** Description: Set function sets character strength
*********************************************************************/
void Character::setStrength(int s) {
	strength = s;
}

/*********************************************************************
** Description: Get function returns character strength
*********************************************************************/
int Character::getStrength() {
	return strength;
}

/*********************************************************************
** Description: Set function sets character armor
*********************************************************************/
void Character::setArmor(int r) {
	armor = r;
}

/*********************************************************************
** Description: Get function returns character armor
*********************************************************************/
int Character::getArmor() {
	return armor;
}

/*********************************************************************
** Description: Void function recharges 50% of the damage to strength.
*********************************************************************/
void Character::recharge() {
	if (type == "Vampire") {
		strength = strength + ((18 - strength) / 2);
	}
	else if (type == "Barbarian") {
		strength = strength + ((12 - strength) / 2);
	}
	else if (type == "Blue Men") {
		strength = strength + ((12 - strength) / 2);
	}
	else if (type == "Medusa") {
		strength = strength + ((8 - strength) / 2);
	}
	else if (type == "Harry Potter") {
		if (strength <= 10) {
			strength = strength + ((10 - strength) / 2);
		}
	}
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Character::~Character() {

}