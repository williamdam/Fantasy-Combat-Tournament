/*********************************************************************
** Author: William Dam
** Date: 11-16-2019
** Description: Player.hpp is the specification file for the
** Player structure.  Constructor/Destructor defined in separate
** implementation file, Player.cpp.
*********************************************************************/
#ifndef Player_hpp
#define Player_hpp
#include <string>
#include "Character.hpp"

struct Player {

	Player();				// Default constructor
	~Player();				// Destructor
	std::string name;		// Name for the player
	Character* c;			// Character object
	Player* next;			// Ptr to next
	Player* prev;			// Ptr to prev

};

#endif