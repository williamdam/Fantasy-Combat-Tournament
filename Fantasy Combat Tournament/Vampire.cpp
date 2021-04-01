/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Vampire.cpp is the class implementation file for the
** Vampire class.  Vampire is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "Vampire.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
Vampire::Vampire() {
	Character::setStrength(18);		// Initialize strength to 18
	Character::setArmor(1);			// Initialize armor to 1
	Character::setType("Vampire");	// Initialize type to Vampire
	damage = 0;						// Initialize damage to 0
}

/*********************************************************************
** Description: Attack function returns attack power
*********************************************************************/
int Vampire::launchAttack() {
	int attackPower = 0;			
	attackPower = dieRoll(12, 1);	// Attack die roll

	// Display attack roll
	std::cout << "VAMPIRE ATTACK ROLL: " << attackPower << std::endl;

	// Return attack roll
	return attackPower;
}

/*********************************************************************
** Description: Defense function takes attack arg and returns damage
*********************************************************************/
int Vampire::launchDefense(int a) {
	int defensePower = dieRoll(6, 1);	// Defense die roll

	// Calculate damage
	damage = a - defensePower - Character::getArmor();

	if (damage < 0) {
		damage = 0;	// Set damage to 0 if negative
	}
	
	// Display defense roll
	std::cout << "VAMPIRE DEFENSE ROLL: " << defensePower << std::endl;
	charm();	// Apply vampire charm defense

	// Update strength with damage
	Character::setStrength(Character::getStrength() - damage);
	if (Character::getStrength() < 0) {
		Character::setStrength(0);
	}

	return damage;
}

/*********************************************************************
** Description: Void function for charm 50% probability that enemy
** doesn't attack, resulting in 0 damage.
*********************************************************************/
void Vampire::charm() {
	int charm = dieRoll(2, 1);	// Charm die roll
	if (charm == 1) {
		// Display vampire charm notification
		std::cout << "VAMPIRE CHARM!!! ENEMY DOESN'T ATTACK!" << std::endl;
		damage = 0;	// Set damage to 0
	}
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Vampire::~Vampire() {

}