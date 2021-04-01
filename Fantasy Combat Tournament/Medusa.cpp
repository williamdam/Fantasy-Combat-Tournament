/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Medusa.cpp is the class implementation file for the
** Medusa class.  Medusa is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Medusa.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Medusa::Medusa() {
	Character::setStrength(8);		// Initialize strength to 8
	Character::setArmor(3);			// Initialize armor to 3
	Character::setType("Medusa");	// Initialize type to Medusa
	attackPower = 0;				// Initialize attack power
}

/*********************************************************************
** Description: Attack function returns attack power
*********************************************************************/
int Medusa::launchAttack() {
	resetAttackPower();				// Reset attack power
	attackPower += dieRoll(6, 1);	// Die roll 1
	attackPower += dieRoll(6, 1);	// Die roll 2
	
	// Display attack roll
	std::cout << "MEDUSA ATTACK ROLL: " << attackPower << std::endl;

	glare(attackPower);	// Apply Medusa Glare attack

	return attackPower;	// Return attack roll
}

/*********************************************************************
** Description: Defense function takes attack arg and returns damage
*********************************************************************/
int Medusa::launchDefense(int a) {
	int defensePower = dieRoll(6, 1);	// Defense die roll

	// Calculate damage
	int damage = a - defensePower - Character::getArmor();

	if (damage < 0) {
		damage = 0;		// Set damage to 0 if negative
	}
	
	// Display defense roll
	std::cout << "MEDUSA DEFENSE ROLL: " << defensePower << std::endl;

	// Update strength with damage
	Character::setStrength(Character::getStrength() - damage);
	if (Character::getStrength() < 0) {
		Character::setStrength(0);
	}

	return damage;
}

/*********************************************************************
** Description: Void function for Medusa glare.  If attack roll is 12
** the opponent instantly dies.
*********************************************************************/
void Medusa::glare(int a) {

	if (a == 12) {
		std::cout << "MEDUSA USES GLARE!!!  INSTANT DEATH." << std::endl;
		attackPower = 999;	// Set attack power to 999
	}
}

/*********************************************************************
** Description: Void function to reset the attack power.
*********************************************************************/
void Medusa::resetAttackPower() {
	attackPower = 0;
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Medusa::~Medusa() {

}