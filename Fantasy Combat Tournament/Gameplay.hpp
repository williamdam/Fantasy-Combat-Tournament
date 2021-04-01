/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Gameplay.hpp is the specification file for the
** Gameplay class.  Member functions defined in separate implementation
** file, Gameplay.cpp.
*********************************************************************/
#ifndef Gameplay_hpp
#define Gameplay_hpp
#include "Team1.hpp"
#include "Team2.hpp"
#include "Losers.hpp"

class Gameplay {

public:
	Gameplay();					// Default constructor
	~Gameplay();				// Class Destructor

	void lineSeparator();		// Line separator

	void printStartMenu();		// Start menu 1) Play 2) Exit
	void printContinueMenu();	// Continue menu 1) Play Again 2) Exit
	void setNumPlayers();		// Set number of players
	void printCharOptions();	// Print characters to choose from
	void printFightMenu();		// Print fight menu 1) Fight 2) Quit

	void populateTeam1();		// Add players to Team 1
	int team1Attack();			// Team 1 player attack
	int team1Defense(int a);	// Team 1 player defense

	void populateTeam2();		// Add players to Team 2
	int team2Attack();			// Team 2 player attack
	int team2Defense(int a);	// Team 2 player defense

	void team1AttackSequence();	// Team 1 attack sequence
	void team2AttackSequence();	// Team 2 attack sequence

	int firstAttack();			// Get choice for team attacking first
	void battle(int f);			// Battle between teams til death
	int whoDied();				// Check and return who died
	void shufflePlayers(int d);	// Move winner to back, loser to loser list
	bool teamsAlive();			// Check if teams alive
	void clearAllLists();		// Clear teams and loser list

	void printGoodbye();		// Print goodbye
	void printWinner();			// Print Teams winner and loser
	void printFighterSummary();	// Print Fighters winner and loser
	void printLoserOption();	// Option to print loser list

private:
	Team1* fighter1;	// Pointer to Team1 object
	Team2* fighter2;	// Pointer to Team2 object
	Losers* loserList;	// Pointer to Losers object
	Player* temp;		// Temp pointer for players
	int numPlayers;		// Number of players
	int round;			// Fight round
};

#endif
