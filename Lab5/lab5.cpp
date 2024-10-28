/*
	Andrew Banks
	Computer Science Fall 2024
	Due: 10/15/2024
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
	
	while (true)
	{
		
		std::cout << "1. Play Game" << std::endl;
		std::cout << "2. Change Guess limit" << std::endl;
		std::cout << "2. All time scores" << std::endl;
		std::cout << "3. Quit" << std::endl;

		std::cout << "Please enter your choice: ";
		std::cin >> choice;

		game.getAllTimeScores();
		switch (choice)
		{
		case 1:
			std::cout << "You have chosen to play the game!" << std::endl;
			game.playGame();
			break;
		case 2:
			std::cout << "You have chosen to see the all time scores!" << std::endl;
			game.displayAllTimeScores();
			break;
		case 3:
			std::cout << "You have chosen to quit the game!" << std::endl;
			return 0;
		default:
			std::cout << "Invalid choice, please try again!" << std::endl;
			break;
		}
	}

	return 0;

}