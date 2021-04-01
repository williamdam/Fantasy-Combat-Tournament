/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Barbarian.hpp is the class specification file for the
** Barbarian class.  Barbarian is a derived class of the Character base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef Barbarian_hpp
#define Barbarian_hpp
#include "Character.hpp"
#include <string>

class Barbarian : public Character
{

public:
	Barbarian();				// Default constructor
	~Barbarian();				// Destructor

	int launchAttack();			// Attack function
	int launchDefense(int a);	// Defense function

private:

};

#endif