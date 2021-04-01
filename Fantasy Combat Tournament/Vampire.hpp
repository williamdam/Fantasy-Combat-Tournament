/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Vampire.hpp is the class specification file for the
** Vampire class.  Vampire is a derived class of the Character base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef Vampire_hpp
#define Vampire_hpp
#include "Character.hpp"
#include <string>

class Vampire: public Character
{

public:
	Vampire();					// Default constructor
	~Vampire();					// Destructor

	int launchAttack();			// Attack function
	int launchDefense(int a);	// Defense function
	void charm();				// Vampire charm

private:
	int damage;					// Damage
};

#endif