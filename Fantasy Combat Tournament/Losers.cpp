/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Losers.cpp is the implementation file for the
** Losers class.  This class is a circular linked list of Player
** objects.  Member functions defined within.
*********************************************************************/
#include "Losers.hpp"
#include <iostream>
#include <string>

/*********************************************************************
** Description: Default constructor for Queue class
*********************************************************************/
Losers::Losers() {
	n = nullptr;			// Initialize n ptr to null
	head = nullptr;			// Initialize head ptr to null
	tail = nullptr;			// Initialize tail ptr to null
	navigator = nullptr;	// Initialize navigator ptr to null
}

/*********************************************************************
** Description: Print function displays line separator
*********************************************************************/
void Losers::lineSeparator() {
	for (int i = 0; i < 75; i++) {
		std::cout << "-";	// Print 75 hyphens for line separator
	}
	std::cout << std::endl;
}

/*********************************************************************
** Description: Bool function checks to see if list is empty and
** returns bool.  Empty = true.
*********************************************************************/
bool Losers::isEmpty() {
	if (head == nullptr) {
		return true;			// Return true if list is empty
	}
	else {
		return false;			// Return false if list is not empty
	}
}

/*********************************************************************
** Description: Void function adds node to front of queue.  Takes
** Player object as argument.
*********************************************************************/
void Losers::addHead(Player* incoming) {

	// If the list is empty
	if (isEmpty() == true) {
		n = incoming;			// Create new node, n
		head = n;				// Set head to n
		tail = n;				// Set tail to n
		n->prev = tail;			// Set prev ptr to tail
		n->next = head;			// Set next ptr to head
	}

	// If list already has 1 or more nodes
	else {
		n = incoming;			// Create new node, n
		n->next = head;			// Set next ptr to head
		n->prev = tail;			// Set prev ptr to tail
		tail->next = n;			// Set tail next to n
		head->prev = n;			// Set head prev to n
		head = n;				// Update head
	}

	lineSeparator();
	std::cout << "Player added to loser list." << std::endl;
	printTeam();				// Print loser list
}

/*********************************************************************
** Description: Print function displays name and character type of
** each player in the list.
*********************************************************************/
void Losers::printTeam() {

	lineSeparator();

	// If queue is empty, then say so
	if (isEmpty() == true) {
		std::cout << "List is empty!" << std::endl;
	}

	// Otherwise, queue has nodes, so do this
	else {
		int count = 0;		// Set count to 0
		navigator = head;	// Set navigator ptr to head

		std::cout << "The loser list looks like this: " << std::endl;

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
** Description: Clear the list of objects and reset pointers to null.
** This function is used when restarting the game.
*********************************************************************/
void Losers::clearList() {
	// While there is more than one node

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
** Description: Destructor for Queue class
*********************************************************************/
Losers::~Losers() {

	// While there is more than one node
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