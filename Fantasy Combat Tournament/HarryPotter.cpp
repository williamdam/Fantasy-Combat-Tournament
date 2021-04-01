/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: HarryPotter.cpp is the class implementation file for the
** HarryPotter class.  HarryPotter is a derived class of the Character base
** class.  Member methods are defined within.
*********************************************************************/
#include "HarryPotter.hpp"
#include <iostream>

/*********************************************************************
** Description: Default constructor
*********************************************************************/
HarryPotter::HarryPotter() {
	Character::setStrength(10);			// Initialize strength 10
	Character::setArmor(0);				// Initialize armor 0
	Character::setType("Harry Potter");	// Initialize type Harry Potter
	lives = 2;							// Initialize lives 2
}

/*********************************************************************
** Description: Attack function returns attack power
*********************************************************************/
int HarryPotter::launchAttack() {
	int attackPower = 0;
	attackPower += dieRoll(6, 1);		// Attack die roll 1
	attackPower += dieRoll(6, 1);		// Attack die roll 2

	// Display attack roll
	std::cout << "HARRY POTTER ATTACK ROLL: " << attackPower << std::endl;
	return attackPower;	// Return attack roll
}

/*********************************************************************
** Description: Defense function takes attack arg and returns damage
*********************************************************************/
int HarryPotter::launchDefense(int a) {
	int defensePower = 0;

	defensePower += dieRoll(6, 1);	// Defense roll 1
	defensePower += dieRoll(6, 1);	// Defense roll 2

	// Calculate damage
	int damage = a - defensePower - Character::getArmor();

	if (damage < 0) {
		damage = 0;		// Set damage to 0 if negative
	}

	// Display defense roll
	std::cout << "HARRY POTTER DEFENSE ROLL: " << defensePower << std::endl;
	
	// Update strength with damage
	Character::setStrength(Character::getStrength() - damage);
	if (Character::getStrength() < 0) {
		Character::setStrength(0);
	}
	hogwarts();	// Apply Gogwarts magic to restore strength
	return damage;	
}

/*********************************************************************
** Description: Void function for Hogwarts power.  Character has 2 lives.
** When strength hits 0, strength goes back up, but to 20.  Can only
** happen once.
*********************************************************************/
void HarryPotter::hogwarts() {
	if (lives == 2 && Character::getStrength() <= 0) {
		Character::setStrength(20);		// Set strength to 20
		std::cout << "HARRY POTTER USED HOGWARTS MAGIC!" << std::endl;
		std::cout << "Strength is now at: " << Character::getStrength() << std::endl;
		lives--;	// Decrement lives
	}
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
HarryPotter::~HarryPotter() {

}