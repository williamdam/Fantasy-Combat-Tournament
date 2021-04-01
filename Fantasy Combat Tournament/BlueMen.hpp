/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: BlueMen.hpp is the class specification file for the
** BlueMen class.  BlueMen is a derived class of the Character base
** class.  Member functions defined in separate implementation file.
*********************************************************************/
#ifndef BlueMen_hpp
#define BlueMen_hpp
#include "Character.hpp"
#include <string>

class BlueMen : public Character
{

public:
	BlueMen();					// Default constructor
	~BlueMen();					// Destructor

	int launchAttack();			// Attack function
	int launchDefense(int a);	// Defense function
	void mob();					// Blue Men mob

private:
	int defenseDice;			// Number of defense dice
};

#endif