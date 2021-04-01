/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: BlueMen.cpp is the class implementation file for the
** BlueMen class.  BlueMen is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "BlueMen.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
BlueMen::BlueMen() {
	Character::setStrength(12);		// Initialize strength to 12
	Character::setArmor(3);			// Initialize armor to 3
	Character::setType("Blue Men");	// Initialize type to Blue Men
	defenseDice = 3;				// Initialize number of defense dice
}

/*********************************************************************
** Description: Attack function returns attack power
*********************************************************************/
int BlueMen::launchAttack() {
	int attackPower = 0;
	attackPower += dieRoll(10, 1);	// Attack die roll 1
	attackPower += dieRoll(10, 1);	// Attack die roll 2

	// Display attack roll
	std::cout << "BLUE MEN ATTACK ROLL: " << attackPower << std::endl;

	// Return attack roll
	return attackPower;
}

/*********************************************************************
** Description: Defense function takes attack arg and returns damage
*********************************************************************/
int BlueMen::launchDefense(int a) {
	int defensePower = 0;
	
	for (int i = 0; i < defenseDice; i++) {
		defensePower += dieRoll(6, 1);		// Defense die roll
	}
	
	// Calculate damage
	int damage = a - defensePower - Character::getArmor();

	if (damage < 0) {
		damage = 0;		// Set damage to 0 if negative
	}
	
	// Display defense roll
	std::cout << "BLUE MEN DEFENSE ROLL: " << defensePower << std::endl;
	mob();	// Apply Blue Men mob, where they lose dice

	// Update strength with damage
	Character::setStrength(Character::getStrength() - damage);
	if (Character::getStrength() < 0) {
		Character::setStrength(0);
	}

	return damage;
}

/*********************************************************************
** Description: Void function for mob power.  Every loss of 8 strength
** points results in the loss of 1 defense die.
*********************************************************************/
void BlueMen::mob() {
	if (Character::getStrength() <= 8 && defenseDice == 3) {
		defenseDice--;		// Decrement dice
		std::cout << "DEFENDER JUST LOST 1 DEFENSE DIE!" << std::endl;
		std::cout << "DICE REMAINING: " << defenseDice << std::endl;
		
	}
	if (Character::getStrength() <= 4 && defenseDice == 2) {
		defenseDice--;		// Decrement dice
		std::cout << "DEFENDER JUST LOST ANOTHER DEFENSE DIE!" << std::endl;
		std::cout << "DICE REMAINING: " << defenseDice << std::endl;
	}
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
BlueMen::~BlueMen() {

}