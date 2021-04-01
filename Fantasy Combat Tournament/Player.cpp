/*********************************************************************
** Author: William Dam
** Date: 11-16-2019
** Description: Player.cpp is the implementation file for the
** Player structure.  Constructor/Destructor defined within.
*********************************************************************/
#include "Player.hpp"
#include <string>

/*********************************************************************
** Description: Default constructor for Player structure
*********************************************************************/
Player::Player() {
	name = "";			// Name of this player
	c = nullptr;		// Character for this player
	next = nullptr;		// Ptr to next
	prev = nullptr;		// Ptr to prev
}

/*********************************************************************
** Description: Default constructor for Player structure
*********************************************************************/
Player::~Player() {

}