/*********************************************************************
** Author: William Dam
** Date: 11-19-2019
** Description: Gameplay.cpp is the implementation file for the
** Gameplay class.  Member functions defined within.
*********************************************************************/
#include "Gameplay.hpp"
#include <iostream>
#include "Validate.hpp"
#include <string>
#include <iostream>

/*********************************************************************
** Description: Default constructor initializes both team lists, 
** loser list, temp pointer, number of players per team, and round.
*********************************************************************/
Gameplay::Gameplay() {
	fighter1 = new Team1();		// Instantiate Team 1 list
	fighter2 = new Team2();		// Instantiate Team 2 list
	loserList = new Losers();	// Instantiate Loser list
	temp = nullptr;				// Initialize temp ptr 
	numPlayers = 0;				// Initialize numPlayers
	round = 1;					// Initialize round
}

/*********************************************************************
** Description: Print function displays horizontal line.
*********************************************************************/
void Gameplay::lineSeparator() {
	for (int i = 0; i < 75; i++) {
		std::cout << "-";		// Print 75 "-" marks as line separator
	}
	std::cout << std::endl;
}

/*********************************************************************
** Description: Print function displays start menu.  1) Play 2) Exit
*********************************************************************/
void Gameplay::printStartMenu() {
	lineSeparator();
	std::cout << "WELCOME TO FANTASY COMBAT TOURNAMENT!" << std::endl;
	std::cout << "1. Play" << std::endl;
	std::cout << "2. Exit" << std::endl;
	lineSeparator();
}

/*********************************************************************
** Description: Print function displays continue menu.  1) Play 2) Exit
*********************************************************************/
void Gameplay::printContinueMenu() {
	lineSeparator();
	std::cout << "FANTASY COMBAT MAIN MENU" << std::endl;
	std::cout << "1. Play Again" << std::endl;
	std::cout << "2. Exit" << std::endl;
	lineSeparator();
}

/*********************************************************************
** Description: Set function sets number of players.  One input used
** for both teams.  (e.g. SetNumPlayers(5) indicates 5 players per
** team.
*********************************************************************/
void Gameplay::setNumPlayers() {
	std::cout << "Enter number of players per team: ";
	numPlayers = integerInput(1, 10);
}

/*********************************************************************
** Description: Print function displays list of characters to choose
** from.
*********************************************************************/
void Gameplay::printCharOptions() {
	std::cout << "FANTASY COMBAT GAME - CHARACTERS" << std::endl;
	std::cout << "1. Vampire" << std::endl;
	std::cout << "2. Barbarian" << std::endl;
	std::cout << "3. Blue Men" << std::endl;
	std::cout << "4. Medusa" << std::endl;
	std::cout << "5. Harry Potter" << std::endl;
}

/*********************************************************************
** Description: Print function displays fight menu.
*********************************************************************/
void Gameplay::printFightMenu() {
	std::cout << "1. Fight" << std::endl;
	std::cout << "2. Quit Battle" << std::endl;
	std::cout << "Enter your selection: ";
}

/*********************************************************************
** Description: Void function adds players to Team 1. Takes user input
** for player name, and type of character.
*********************************************************************/
void Gameplay::populateTeam1() {
	int count = 0;					// Count based on numPlayers
	std::string playerName = "";	// String for player name
	int charOption = 0;				// Character option

	printCharOptions();				// Print character options

	for (int i = 0; i < numPlayers; i++) {

		count++;	// Increment count
		std::cout << "Team 1 - Player " << count << std::endl;
		std::cout << "Enter a Name: ";
		std::getline(std::cin, playerName);		// Get player name
		std::cout << "Enter Character Option: ";
		charOption = integerInput(1, 5);		// Get character option

		// Add player to Team 1 list
		fighter1->addBack(playerName, charOption);
	}

}

/*********************************************************************
** Description: Int function calls Team 1 attack function, and returns
** attack power.
*********************************************************************/
int Gameplay::team1Attack() {
	std::cout << "TEAM 1 ATTACK" << std::endl;
	int attackPower = fighter1->attack();	// Team 1 attack
	return attackPower;						// Return attack power
}

/*********************************************************************
** Description: Void function calls Team 1 defense function. Takes 
** opponents attackPower value as argument.  Calls defense function
** from character, and returns defense power.
*********************************************************************/
int Gameplay::team1Defense(int a) {
	std::cout << "TEAM 1 DEFENSE" << std::endl;
	int defensePower = fighter1->defense(a);
	return defensePower;
}

/*********************************************************************
** Description: Void function adds players to Team 2. Takes user input
** for player name, and type of character.
*********************************************************************/
void Gameplay::populateTeam2() {
	int count = 0;					// Count based on numPlayers
	std::string playerName = "";	// String for player name
	int charOption = 0;				// Character option

	printCharOptions();				// Print character options

	for (int i = 0; i < numPlayers; i++) {

		count++;	// Increment count
		std::cout << "Team 2 - Player " << count << std::endl;
		std::cout << "Enter a Name: ";
		std::getline(std::cin, playerName);			// Get player name
		std::cout << "Enter Character Option: ";
		charOption = integerInput(1, 5);			// Get character option

		// Add player to Team 2 list
		fighter2->addBack(playerName, charOption);
	}
}

/*********************************************************************
** Description: Int function calls Team 2 attack function, and returns
** attack power.
*********************************************************************/
int Gameplay::team2Attack() {
	std::cout << "TEAM 2 ATTACK" << std::endl;
	int attackPower = fighter2->attack();
	return attackPower;
}

/*********************************************************************
** Description: Void function calls Team 2 defense function. Takes
** opponents attackPower value as argument.  Calls defense function
** from character, and returns defense power.
*********************************************************************/
int Gameplay::team2Defense(int a) {
	std::cout << "TEAM 2 DEFENSE" << std::endl;
	int defensePower = fighter2->defense(a);
	return defensePower;
}

/*********************************************************************
** Description: Team 1 attacks and spits attack power.  Team 2 defends
** and spits damage power.  Display total damage inflicted.
*********************************************************************/
void Gameplay::team1AttackSequence() {
	std::cout << "TEAM 1 IS ATTACKING!" << std::endl;

	int attack = team1Attack();			// Player 1 Attack
	int damage = team2Defense(attack);	// Player 2 Defense

	// Print fighter 2 armor
	std::cout << "Plus additional armor: " << fighter2->getHeadArmor();
	std::cout << std::endl;	

	// Print fighter 2 damage
	std::cout << "Total Damage Inflicted: " << damage << std::endl;	
}

/*********************************************************************
** Description: Team 2 attacks and spits attack power.  Team 1 defends
** and spits damage power.  Display total damage inflicted.
*********************************************************************/
void Gameplay::team2AttackSequence() {
	std::cout << "TEAM 2 IS ATTACKING!" << std::endl;

	int attack = team2Attack();			// Player 1 Attack
	int damage = team1Defense(attack);	// Player 2 Defense

	// Print fighter 1 armor
	std::cout << "Plus additional armor: " << fighter1->getHeadArmor();
	std::cout << std::endl;	

	// Print fighter 1 damage
	std::cout << "Total Damage Inflicted: " << damage << std::endl;
}

/*********************************************************************
** Description: Checks for players with strength <= 0, and returns
** value.
*********************************************************************/
int Gameplay::whoDied() {
	if (fighter1->getHeadStrength() <= 0) {
		return 1;		// Return 1 if Team 1 fighter dies
	}
	else if (fighter2->getHeadStrength() <= 0) {
		return 2;		// Return 2 if Team 2 fighter dies
	}
	else if (fighter1->getHeadStrength() <= 0 && fighter2->getHeadStrength() <= 0) {
		return 3;		// Return 3 if both fighters die
	}
	else {
		return 4;		// Return 4 if nobody died
	}
}

/*********************************************************************
** Description: Int function displays players and gets input for who
** is attacking first.  Returns integer value based on input.
*********************************************************************/
int Gameplay::firstAttack() {

	// If players not chosen yet, spit message
	if (fighter1->getFront() == nullptr || fighter2->getFront() == nullptr) {
		std::cout << "You haven't chosen players yet!!!" << std::endl;
		return 0;
	}

	else {
		// Print teams that are up against each other
		lineSeparator();
		std::cout << "STAGING THE BATTLE!!!" << std::endl;
		lineSeparator();

		std::cout << "MEET TEAM 1 FIGHTERS" << std::endl;
		fighter1->printTeam();		// Print team 1

		std::cout << std::endl;

		std::cout << "MEET TEAM 2 FIGHTERS" << std::endl;
		fighter2->printTeam();		// Print team 2

		// Get choice for who is attacking first
		std::cout << "Choose who is attacking first: " << std::endl;
		std::cout << "1. Team 1" << std::endl;
		std::cout << "2. Team 2" << std::endl;

		std::cout << "Enter an option: ";
		int attacker = integerInput(1, 2);	// Validate input

		return attacker;	// Return choice
	}
}

/*********************************************************************
** Description: Void function receives int arg and manages the battle.
** Int arg indicates which player is attacking first.  Can be used
** in conjunction with firstAttack().
*********************************************************************/
void Gameplay::battle(int f) {

	// Player 1 is attacking first
	if (f == 1) {

		std::cout << "*TEAM 1 IS ATTACKING FIRST*" << std::endl;

		int fight = 1;					// Initialize option

		// Fight loop continues until player dies or user enters 2
		while (fight != 2) {

			lineSeparator();

			// Round header displays round #, teams, and fighters
			std::cout << "ROUND " << round << ": " << "Team 1 - ";
			std::cout << fighter1->getHeadName() << " (";
			std::cout << fighter1->getHeadType() << ") ";
			std::cout << " vs. " << "Team 2 - ";
			std::cout << fighter2->getHeadName() << " (";
			std::cout << fighter1->getHeadType() << ") " << std::endl;
			lineSeparator();

			if (whoDied() == 4) {		// If players alive
				team1AttackSequence();	// Call player 1 attack sequence
			}

			lineSeparator();

			if (whoDied() == 4) {		// If players alive
				team2AttackSequence();	// Call player 2 counterattack
			}

			// Check to see if a player is down and updates team score
			int playerDown = whoDied();
			if (playerDown != 4) {

				// Increment Team 2 score
				if (playerDown == 1) {
					fighter2->setScore(fighter2->getScore() + 1);	
				}

				// Increment Team 1 score
				else if (playerDown == 2) {
					fighter1->setScore(fighter1->getScore() + 1);	
				}

				lineSeparator();

				// Print summary of battle round
				std::cout << "ROUND " << round << " BATTLE SUMMARY" << std::endl;
				round++;				// Increment round
				printFighterSummary();	// Print fighter summary and team scores

				// Send winner to back of list, loser to loser list
				shufflePlayers(playerDown);	
			}
			
			// If both teams still have players remaining
			if (teamsAlive() == true) {
				fight = 1;	// Loop again for next round
			}

			// If 1 or more teams are dead
			else {
				printWinner();		// Print the winning team summary
				printLoserOption();	// Option to print loser list
				fight = 2;			// Quit loop
			}
		}
	}


	// Player 2 is attacking first
	if (f == 2) {

		std::cout << "*TEAM 2 IS ATTACKING FIRST*" << std::endl;

		int fight = 1;					// Initialize option

		// Fight loop continues until player dies or user enters 2
		while (fight != 2) {

			lineSeparator();

			// Round header displays round #, teams, and fighters
			std::cout << "ROUND " << round << ": " << "Team 1 - ";
			std::cout << fighter1->getHeadName() << " (";
			std::cout << fighter1->getHeadType() << ") ";
			std::cout << " vs. " << "Team 2 - ";
			std::cout << fighter2->getHeadName() << " (";
			std::cout << fighter1->getHeadType() << ") " << std::endl;
			lineSeparator();

			if (whoDied() == 4) {		// If players alive
				team2AttackSequence();	// Call player 1 attack sequence
			}

			lineSeparator();

			if (whoDied() == 4) {		// If players alive
				team1AttackSequence();	// Call player 2 counterattack
			}

			// Check to see if a player is down and updates team score
			int playerDown = whoDied();
			if (playerDown != 4) {

				// Increment Team 2 score
				if (playerDown == 1) {
					fighter2->setScore(fighter2->getScore() + 1);
				}

				// Increment Team 1 score
				else if (playerDown == 2) {
					fighter1->setScore(fighter1->getScore() + 1);
				}

				lineSeparator();

				// Print summary of battle round
				std::cout << "ROUND " << round << " BATTLE SUMMARY" << std::endl;
				round++;				// Increment round
				printFighterSummary();	// Print fighter summary and team scores

				// Send winner to back of list, loser to loser list
				shufflePlayers(playerDown);
			}

			// If both teams still have players remaining
			if (teamsAlive() == true) {
				fight = 1;	// Loop again for next round
			}

			// If 1 or more teams are dead
			else {
				printWinner();		// Print the winning team summary
				printLoserOption();	// Option to print loser list
				fight = 2;			// Quit loop
			}
		}
	}

}

/*********************************************************************
** Description: Void function sends dead players to loser list and
** winning players to end of their respective lists.  Function called
** anytime a player dies.
*********************************************************************/
void Gameplay::shufflePlayers(int d) {
	
	if (d == 1) {		// If player 1 dies

		lineSeparator();

		std::cout << "Player 1 died." << std::endl;
		temp = fighter1->getFront();	// Set ptr to loser
		fighter1->updateHead();			// Set 2nd fighter as head
		loserList->addHead(temp);		// Move loser to loser list
		fighter2->sendToBack();			// Send winner to back of list
		
		lineSeparator();
	}
	
	else if (d == 2) {	// If player 2 dies
		
		lineSeparator();
		
		std::cout << "Player 2 died." << std::endl;
		temp = fighter2->getFront();	// Set ptr to loser
		fighter2->updateHead();			// Set 2nd fighter as head
		loserList->addHead(temp);		// Move loser to loser list
		fighter1->sendToBack();			// Send winner to back of list
		
		lineSeparator();
	}
	
	else if (d == 3) {	// If both players dead
		lineSeparator();
		std::cout << "Both players died." << std::endl;
		temp = fighter1->getFront();	// Set ptr to loser
		fighter1->updateHead();			// Set 2nd fighter as head
		loserList->addHead(temp);		// Move loser to loser list

		temp = fighter2->getFront();	// Set ptr to loser
		fighter2->updateHead();			// Set 2nd fighter as head
		loserList->addHead(temp);		// Move loser to loser list
		
		lineSeparator();
	}
}

/*********************************************************************
** Description: bool function checks to see if all teams still have
** players remaining.  Returns bool value, true if all teams have
** players remaining.
*********************************************************************/
bool Gameplay::teamsAlive() {

	bool alive = true;	// True if both teams have players remaining

	// Team 1 is empty
	if (fighter1->isEmpty() == true) {
		std::cout << "All fighters in Team 1 died." << std::endl;
		alive = false;	// Set bool false
	}

	// Team 2 is empty
	else if (fighter2->isEmpty() == true) {
		std::cout << "All fighters in Team 2 died." << std::endl;
		alive = false;	// Set bool false
	}

	// Both teams are empty
	else if (fighter1->isEmpty() == true && fighter2->isEmpty() == true) {
		std::cout << "BOTH TEAMS DIED!!!" << std::endl;
		alive = false;	// Set bool false
	}

	else {
		alive = true;	// Set bool true
	}

	return alive;		// Return bool
}

/*********************************************************************
** Description: Print function displays each team's score, indicates
** which team is the winner, or tie game.  Prints loser list.
*********************************************************************/
void Gameplay::printWinner() {

	lineSeparator();
	std::cout << "OVERALL BATTLE SUMMARY" << std::endl;
	lineSeparator();

	// Print both team scores
	std::cout << "Team 1 Score: " << fighter1->getScore() << std::endl;
	std::cout << "Team 2 Score: " << fighter2->getScore() << std::endl;

	// Print the winning team
	if (fighter1->getScore() > fighter2->getScore()) {
		std::cout << "TEAM 1 WINS!" << std::endl;
	}
	else if (fighter1->getScore() < fighter2->getScore()) {
		std::cout << "TEAM 2 WINS!" << std::endl;
	}
	else if (fighter1->getScore() == fighter2->getScore()) {
		std::cout << "TIE GAME." << std::endl;
	}

}

/*********************************************************************
** Description: Print function displays both fighters and team scores.
*********************************************************************/
void Gameplay::printFighterSummary() {
	
	lineSeparator();

	// Print Team 1 fighter and strength
	std::cout << "Team 1 - " << fighter1->getHeadName() << " - ";
	std::cout << fighter1->getHeadType() << " - Strength: ";
	std::cout << fighter1->getHeadStrength() << std::endl;

	// Print Team 2 fighter and strength
	std::cout << "Team 2 - " << fighter2->getHeadName() << " - ";
	std::cout << fighter2->getHeadType() << " - Strength: ";
	std::cout << fighter2->getHeadStrength() << std::endl;

	// Print team scores
	std::cout << "TEAM 1 SCORE: " << fighter1->getScore() << std::endl;
	std::cout << "TEAM 2 SCORE: " << fighter2->getScore() << std::endl;
}

/*********************************************************************
** Description: Clear Team 1/2 lists, and clear Loser List.
*********************************************************************/
void Gameplay::clearAllLists() {
	fighter1->clearList();		// Clear Team 1 list
	fighter2->clearList();		// Clear Team 2 list
	loserList->clearList();		// Clear Loser list
}

/*********************************************************************
** Description: Print function displays goodbye message.
*********************************************************************/
void Gameplay::printGoodbye() {
	lineSeparator();
	std::cout << "You have quit the game.  Goodbye!" << std::endl;
	lineSeparator();
}

/*********************************************************************
** Description: Print function prompts user and displays loser list.
*********************************************************************/
void Gameplay::printLoserOption() {

	std::cout << "Would you like to see the loser pile?" << std::endl;
	std::cout << "1. Yes" << std::endl;
	std::cout << "2. No" << std::endl;
	std::cout << "Enter an option: ";
	int option = integerInput(1, 2);	// Get user input

	if (option == 1) {
		loserList->printTeam();			// Print loser list
	}
}

/*********************************************************************
** Description: Class destructor
*********************************************************************/
Gameplay::~Gameplay() {

	delete fighter1;
	delete fighter2;
	delete loserList;
}