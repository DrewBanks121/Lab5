/*
	Andrew Banks
	Computer Science Fall 2024
	Due: 11/12/2024
	Lab Name: Lab 5 Number Guessing Game
	Make a number-guessing game 0-100 with 20 max guesses should say win/lost playagain
	do-while loop and switch statement
*/
#include <iostream>
#include "Game.h"

int main() {

	Game game;
	int choice = 0;

	
	std::cout << "Welcome to the Number Guessing Game!" << std::endl;
	
	// Main menu siwtch statement
	while (true)
	{
		
		std::cout << "1. Play Game" << std::endl; //start the game
		std::cout << "2. All time scores" << std::endl; //display all time scores
		std::cout << "3. Quit" << std::endl; //end game and display all time scores
		std::cout << "4. Reset Scores" << std::endl; //added reset scores option

		std::cout << "Please enter your choice: ";
		std::cin >> choice;
		if (std::cin.fail()) //checks if the input is valid
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Invalid choice, please try again!" << std::endl;
			continue;
		}
		
		game.getAllTimeScores();
		switch (choice) //switch statement for the main menu
		{
		case 1:
			//starts the game
			std::cout << "You have chosen to play the game!" << std::endl;
			game.playGame();
			break;
		case 2:
			//tells you all time scores
			std::cout << "You have chosen to see the all time scores!" << std::endl;
			game.displayAllTimeScores();
			break;
		case 3:
			//quits the game and displays all time scores
			std::cout << "You have chosen to quit the game!" << std::endl;
			std::cout << "The all time ratio is" << std::endl;
			game.displayAllTimeScores();
			return 0;
		case 4:
			//resets the scores
			std::cout << "You have chosen to reset the scores!" << std::endl;
			game.resetScores();
			break;
		default:
			std::cout << "Invalid choice, please try again!" << std::endl;
			break;
		}
	}

	return 0;

}