/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Medusa.hpp is the class specification file for the
** Medusa class.  Medusa is a derived class of the Character base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef Medusa_hpp
#define Medusa_hpp
#include "Character.hpp"
#include <string>

class Medusa : public Character
{

public:
	Medusa();					// Default constructor
	~Medusa();					// Destructor

	int launchAttack();			// Attack function
	int launchDefense(int a);	// Defense function
	void glare(int a);			// Medusa glare
	void resetAttackPower();	// Reset attack power

private:
	int attackPower;			// Attack power
};

#endif