/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Team2.hpp is the specification file for the
** Team2 class.  This class is a circular linked list of Player
** objects.  Member functions defined in separate implementation
** file, Team1.cpp.
*********************************************************************/
#ifndef Team2_hpp
#define Team2_hpp
#include "Player.hpp"
#include <string>

class Team2
{

public:
	Team2();				// Default constructor
	~Team2();				// Destructor
	void lineSeparator();	// Print line separator
	bool isEmpty();			// Check if list is empty
	void addBack(std::string name, int choice);	// void function add node to back
	void printTeam();		// Print team roster
	Player* getFront();		// Get front player object
	void updateHead();		// Update head of list
	void sendToBack();		// Send head to back of list

	std::string getHeadName();		// Get player name at head
	std::string getHeadType();		// Get player type at head
	int getHeadArmor();				// Get player armor at head
	int getHeadStrength();			// Get player strength at head
	void setHeadStrength(int p);	// Set player strength at head
	void printHeadPlayer();			// Print player info at head

	int attack();					// Calls character's attack function
	int defense(int a);				// Calls character's defense function

	int getScore();					// Get team score
	void setScore(int s);			// Set team score

	void clearList();				// Clear list

private:
	Player* n;			// Pointer for new nodes
	Player* head;		// Pointer to head
	Player* tail;		// Pointer to tail
	Player* navigator;	// Multipurpose pointer to navigate queue
	int score;			// Team score
};

#endif