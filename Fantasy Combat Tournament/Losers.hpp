/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Losers.hpp is the specification file for the
** Losers class.  This class is a circular linked list of Player
** objects.  Member functions defined in separate implementation
** file, Losers.cpp.
*********************************************************************/
#ifndef Losers_hpp
#define Losers_hpp
#include "Player.hpp"
#include <string>

class Losers
{

public:
	Losers();						// Default constructor
	~Losers();						// Destructor
	void lineSeparator();			// Print line separator
	bool isEmpty();					// Check if list is empty
	void addHead(Player* incoming);	// void function add node to back
	void printTeam();				// Print team roster
	void clearList();				// Clear list

private:
	Player* n;			// Pointer for new nodes
	Player* head;		// Pointer to head
	Player* tail;		// Pointer to tail
	Player* navigator;	// Multipurpose pointer to navigate queue
};

#endif