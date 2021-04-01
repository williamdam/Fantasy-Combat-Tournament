/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Character.hpp is the class specification for the 
** Character class.  Character is a base class for all game characters.
** Member methods defined in separate implementation file.
*********************************************************************/
#ifndef Character_hpp
#define Character_hpp
#include <string>
#include <iostream>

class Character
{

public:
	Character();		// Default constructor
	~Character();		// Destructor

	int dieRoll(int h, int l);		// Generate die roll

	void setType(std::string n);	// Set character type
	std::string getType();			// Get character type

	void setStrength(int s);		// Set character strength 
	int getStrength();				// Get character strength

	void setArmor(int r);			// Set character armor
	int getArmor();					// Get character armor

	virtual int launchAttack();			// Virtual function Attack
	virtual int launchDefense(int a);	// Virtual function Defense

	void recharge();

private:
	int armor;			// Character armor
	int strength;		// Character strength
	std::string type;	// Character type

};

#endif