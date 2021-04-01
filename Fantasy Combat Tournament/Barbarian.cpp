/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Barbarian.cpp is the class implementation file for the
** Barbarian class.  Barbarian is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Barbarian.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Barbarian::Barbarian() {
	Character::setStrength(12);			// Initialize strength 12
	Character::setArmor(0);				// Initialize armor 0
	Character::setType("Barbarian");	// Initialize type Barbarian
}

/*********************************************************************
** Description: Attack function returns attack power
*********************************************************************/
int Barbarian::launchAttack() {
	int attackPower = 0;
	attackPower += dieRoll(6, 1);	// Attack die roll 1
	attackPower += dieRoll(6, 1);	// Attack die roll 2

	// Display attack roll
	std::cout << "BARBARIAN ATTACK ROLL: " << attackPower << std::endl;
	return attackPower;		// Return attack roll
}

/*********************************************************************
** Description: Defense function gets attack arg and returns damage
*********************************************************************/
int Barbarian::launchDefense(int a) {
	int defensePower = 0;

	defensePower += dieRoll(6, 1);	// Defense die roll 1
	defensePower += dieRoll(6, 1);	// Defense die roll 2

	// Calculate damage
	int damage = a - defensePower - Character::getArmor();

	if (damage < 0) {
		damage = 0;		// Set damage to 0 if negative
	}

	// Update strength with damage
	Character::setStrength(Character::getStrength() - damage);
	if (Character::getStrength() < 0) {
		Character::setStrength(0);
	}

	// Display defense roll
	std::cout << "BARBARIAN DEFENSE ROLL: " << defensePower << std::endl;
	return damage;
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Barbarian::~Barbarian() {

}