/*********************************************************************
** Author: William Dam
** Assignment: Project 4
** Date: 11-19-2019
** Description: Fantasy combat game tournament between 2 teams of 
** fighters. User prompted for number of fighters.  Prompt user to 
** choose number of fighters on each team, then system prompts to 
** select fighters and assign names to each fighter.  Battle function 
** sets up fight between teams where loser moves off the team roster.  
** Team with no fighters remaining, loses.
*********************************************************************/
#include <iostream>
#include "Validate.hpp"
#include "Gameplay.hpp"
#include <string>

int main() {

	Gameplay game;		// Instantiate Gameplay object
	
	// Print start menu 1) Play 2) Quit
	game.printStartMenu();
	std::cout << "Enter an option: ";
	int option = integerInput(1, 2);	// Get user input

	// Main game loop
	while (option != 2) {

		game.clearAllLists();		// Clear team lists and loser list
		game.setNumPlayers();		// Set number of players per team

		game.populateTeam1();		// Choose players for Team 1
		game.populateTeam2();		// Choose players for Team 2

		// Select which team attacks first
		int firstAttack = game.firstAttack();	

		game.battle(firstAttack);	// Battle until one team dies

		game.printContinueMenu();	// Print continue menu
		std::cout << "Enter an option: ";
		option = integerInput(1, 2);	// Input continue or quit
	}
	
	game.printGoodbye();	// Goodbye message

	return 0;
}