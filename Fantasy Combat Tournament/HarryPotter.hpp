/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: HarryPotter.hpp is the class specification file for the
** HarryPotter class.  HarryPotter is a derived class of the Character base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef HarryPotter_hpp
#define HarryPotter_hpp
#include "Character.hpp"
#include <string>

class HarryPotter : public Character
{

public:
	HarryPotter();				// Default constructor
	~HarryPotter();				// Destructor

	int launchAttack();			// Attack function
	int launchDefense(int a);	// Defense function
	void hogwarts();			// Hogwarts power

private:
	int lives;					// Number of lives left
};

#endif