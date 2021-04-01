/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Team2.cpp is the implementation file for the
** Team1 class.  This class is a circular linked list of Player
** objects.  Member functions defined within.
*********************************************************************/
#include "Team2.hpp"
#include "Player.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include <iostream>
#include <string>

/*********************************************************************
** Description: Default constructor for Queue class
*********************************************************************/
Team2::Team2() {
	n = nullptr;			// Initialize n ptr to null
	head = nullptr;			// Initialize head ptr to null
	tail = nullptr;			// Initialize tail ptr to null
	navigator = nullptr;	// Initialize navigator ptr to null
	score = 0;				// Initialize team score to 0
}

/*********************************************************************
** Description: Print function displays line separator
*********************************************************************/
void Team2::lineSeparator() {
	for (int i = 0; i < 75; i++) {
		std::cout << "-";	// Print 75 hyphens for line separator
	}
	std::cout << std::endl;
}

/*********************************************************************
** Description: Bool function checks to see if list is empty and
** returns bool.  Empty = true.
*********************************************************************/
bool Team2::isEmpty() {
	if (head == nullptr) {
		return true;			// Return true if list is empty
	}
	else {
		return false;			// Return false if list is not empty
	}
}

/*********************************************************************
** Description: Void function adds node to back of queue, and sets
** player name and character type using arguments.
*********************************************************************/
void Team2::addBack(std::string name, int choice) {

	// If the list is empty
	if (isEmpty() == true) {
		n = new Player();		// Create new node, n
		head = n;				// Set head to n
		tail = n;				// Set tail to n
		n->name = name;			// Set player name from arg
		n->prev = tail;			// Set prev ptr to tail
		n->next = head;			// Set next ptr to head
	}

	// If list already has 1 or more nodes
	else {
		n = new Player();		// Create new node, n
		n->name = name;			// Set player name from arg
		n->prev = tail;			// Set prev ptr to tail
		n->next = head;			// Set next ptr to head
		tail->next = n;			// Set old tail next ptr to n
		head->prev = n;
		tail = n;				// n is now the tail node
	}

	// Create character object
	if (choice == 1) {
		n->c = new Vampire;
	}
	else if (choice == 2) {
		n->c = new Barbarian;
	}
	else if (choice == 3) {
		n->c = new BlueMen;
	}
	else if (choice == 4) {
		n->c = new Medusa;
	}
	else if (choice == 5) {
		n->c = new HarryPotter;
	}

	lineSeparator();
	std::cout << "Player successfully added to the team." << std::endl;
	printTeam();		// Print team list
}

/*********************************************************************
** Description: Print function displays name and character type of
** each player in the list.
*********************************************************************/
void Team2::printTeam() {

	lineSeparator();

	// If queue is empty, then say so
	if (isEmpty() == true) {
		std::cout << "List is empty!" << std::endl;
	}

	// Otherwise, queue has nodes, so do this
	else {
		int count = 0;		// Set count to 0
		navigator = head;	// Set navigator ptr to head

		std::cout << "Team 2 looks like this: " << std::endl;

		// While navigator isn't pointing to last node in queue
		while (navigator->next != head) {
			count++;	// Increment count

			// Print player name and character type
			std::cout << count << ". " << navigator->name << ": ";
			std::cout << navigator->c->getType() << std::endl;

			navigator = navigator->next;	// Move nav ptr to next node
		}

		// Print the last node: Player name and character type
		count++;
		std::cout << count << ". " << navigator->name << ": ";
		std::cout << navigator->c->getType() << std::endl;
	}

	lineSeparator();
}

/*********************************************************************
** Description: Function returns pointer to the first player in the
** team roster.  Used to pass to Loser class.
*********************************************************************/
Player* Team2::getFront() {

	return head;

}

/*********************************************************************
** Description: Void function updates the head pointer to the 2nd
** player in line.  To be used in conjunction with getFront() function.
*********************************************************************/
void Team2::updateHead() {

	// If only 1 player in list, set head/tail to null
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}

	// Otherwise, do this
	else {
		head = head->next;	// Reassign head
		head->prev = tail;	// New head prev to tail
		tail->next = head;	// Tail next to new head
	}
}

/*********************************************************************
** Description: Void function sends first player to the back of the
** list.
*********************************************************************/
void Team2::sendToBack() {

	navigator = head->next;		// Set navigator ptr to 2nd player
	tail->next = head;			// Tail next points to old head
	head->prev = tail;			// Old head prev points to old tail
	head->next = navigator;		// Old head next points to navigator
	navigator->prev = head;		// Navigator prev points to old head
	tail = head;				// Update tail
	head = navigator;			// Update head

	tail->c->recharge();		// Recharge player strength
}

/*********************************************************************
** Description: Get function returns name of player at head.
*********************************************************************/
std::string Team2::getHeadName() {

	return head->name;

}

/*********************************************************************
** Description: Get function returns character of player at head.
*********************************************************************/
std::string Team2::getHeadType() {

	return head->c->getType();

}

/*********************************************************************
** Description: Get function returns armor of player at head.
*********************************************************************/
int Team2::getHeadArmor() {

	return head->c->getArmor();

}

/*********************************************************************
** Description: Get function returns strength of player at head.
*********************************************************************/
int Team2::getHeadStrength() {

	return head->c->getStrength();

}

/*********************************************************************
** Description: Set function takes int arg and sets strength of player
** at head.
*********************************************************************/
void Team2::setHeadStrength(int p) {

	head->c->setStrength(p);

}

/*********************************************************************
** Description: Print function displays name, type, and strength of
** player at head of list.
*********************************************************************/
void Team2::printHeadPlayer() {

	std::cout << "Player name: " << head->name << std::endl;
	std::cout << "Player type: " << head->c->getType() << std::endl;
	std::cout << "Player strength: " << head->c->getStrength() << std::endl;

}

/*********************************************************************
** Description: Attack function calls character attack function
** for player at head of list.  Returns attack power.
*********************************************************************/
int Team2::attack() {

	return head->c->launchAttack();

}

/*********************************************************************
** Description: Defense function takes int argument from attack power
** and calls character defense function for player at head of list.
** Returns damage.
*********************************************************************/
int Team2::defense(int a) {

	return head->c->launchDefense(a);

}

/*********************************************************************
** Description: Get function gets team score and returns int.
*********************************************************************/
int Team2::getScore() {

	return score;

}

/*********************************************************************
** Description: Set function takes int argument and sets team score.
*********************************************************************/
void Team2::setScore(int s) {

	score = s;

}

/*********************************************************************
** Description: Void function clears the list of players.  Used when
** starting new game.
*********************************************************************/
void Team2::clearList() {

	if (isEmpty() == false) {
		while (head != tail) {
			navigator = head->next;	// Navigator ptr to 2nd node
			delete head->c;			// Delete character object
			delete head;			// Delete head
			head = navigator;		// Navigator ptr is new head
			tail->next = head;		// Tail next ptr to head
			head->prev = tail;		// Head prev ptr to tail
		}
		delete head->c;			// Delete character object
		delete head;			// Delete head

		n = nullptr;			// Initialize n ptr to null
		head = nullptr;			// Initialize head ptr to null
		tail = nullptr;			// Initialize tail ptr to null
		navigator = nullptr;	// Initialize navigator ptr to null
	}
}

/*********************************************************************
** Description: Destructor for Team1 class
*********************************************************************/
Team2::~Team2() {

	if (isEmpty() == false) {
		while (head != tail) {
			navigator = head->next;	// Navigator ptr to 2nd node
			delete head->c;			// Delete character object
			delete head;			// Delete head
			head = navigator;		// Navigator ptr is new head
			tail->next = head;		// Tail next ptr to head
			head->prev = tail;		// Head prev ptr to tail
		}
		delete head->c;				// Delete character object
		delete head;				// Delete head
	}
}