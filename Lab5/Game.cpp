#include "Game.h"
#include <iostream>
#include <fstream>



Game::Game()
{
	//initialize variables
	guess = 0;
	randomNumber = 0;
	maxGuesses = 0;
	amountOfGuesses = 0;
	playAgain = ' ';
	totalWins = 0;
	totalLosses = 0;

}

Game::~Game()
{
}

void Game::playGame()
{
	//play the game
	if (canPlay == true)
	{
		//do while loop to play the game
		do
		{
			//gets a random number between 0 and 100
			srand(time(0));
			randomNumber = rand() % 100 + 1;
			maxGuesses = 20;
			amountOfGuesses = 0;
			std::cout << "You have 20 guesses to guess the number between 0 and 100!" << std::endl;
			std::cout << "Please enter your guess: ";

			//gets the users guess and check if it's valid
			std::cin >> guess;
			while (guess < 0 || guess > 100)
			{
				std::cout << "Invalid guess, please try again!" << std::endl;
				std::cout << "Please enter your guess: ";
				while (true) {
					std::cin >> guess;

				}

			}
			//while loop to check if the guess is correct
			while (guess != randomNumber && amountOfGuesses < maxGuesses - 1)
			{
				while (std::cin.fail())
				{
					std::cout << std::endl;
					std::cin.clear();
					std::cin.ignore();
					std::cout << "Invalid choice, please try again!" << std::endl;
					std::cout << "Please enter your guess: ";
					std::cin >> guess;
				}
				if (guess < randomNumber)
				{
					std::cout << "Your guess is too low!" << std::endl;
				}
				else
				{
					std::cout << "Your guess is too high!" << std::endl;
				}
				amountOfGuesses++;
				std::cout << "You have " << maxGuesses - amountOfGuesses << " guesses left!" << std::endl;
				std::cout << "Please enter your guess: ";
				std::cin >> guess;
				while (guess < 0 || guess > 100)
				{
					std::cout << "Invalid guess, please try again!" << std::endl;
					std::cout << "Please enter your guess: ";
					std::cin >> guess;
				}
			}
			//if statement to check if the guess is correct
			if (guess == randomNumber)
			{
				getMessagesWinlost();
				totalWins++;
				saveAllTimeScores();
			}
			//if the guess is incorrect
			else
			{
				getMessagesWinlost();
				std::cout << "The correct number was: " << randomNumber << std::endl;
				totalLosses++;
				saveAllTimeScores();
			}
			int i = 0;
			//while loop to check if the player wants to play again
			while (i == 0) {
				getMessages();

				std::cin >> playAgain;
				if (playAgain == "n")
				{
					std::cout << "You have chosen to quit the game!" << std::endl;
					i = 1;
				}
				else if (playAgain == "y")
				{
					std::cout << "You have chosen to play the game!" << std::endl;
					i = 1;
				}
				else if (playAgain == "EASTEREGG")
				{
					EASTEREGGbool = true;
					EASTEREGG();

				}
				else if (playAgain == "HELP" && EASTEREGGbool == true)
				{
					std::cout << "You have saved me! Thank you! I am free!" << std::endl;
					canPlay = false;
					i = 1;
				}
				else
				{
					std::cout << "Invalid choice, please try again!" << std::endl;
				}

			}

		} while (playAgain == "y");

	}
	else
	{
		std::cout << "You have freed the man in the game it will no longer work you must find a new person to trap in" << std::endl;
		std::cout <<" here or you will be trapped forever" << std::endl;
	}
}


//gets the all time scores from a file
void Game::getAllTimeScores()
{
	std::ifstream inputfile;
	inputfile.open("TotalGamesData.dat");
	inputfile >> totalWins;
	inputfile >> totalLosses;
	inputfile.close();
		

}
//save the all time scores to a file
void Game::saveAllTimeScores()
{
	std::ofstream outputfile;
	outputfile.open("TotalGamesData.dat");
	outputfile << totalWins << std::endl;
	outputfile << totalLosses << std::endl;
	outputfile.close();
}
//display the all time scores
void Game::displayAllTimeScores()
{
	std::cout << "Total Wins: " << totalWins << std::endl;
	std::cout << "Total Losses: " << totalLosses << std::endl;
	std::cout << "Win Percentage: " << (totalWins / (totalWins + totalLosses)) * 100 << "%" << std::endl;
}
//gets the messages for if the player wins or loses
void Game::getMessagesWinlost()
{
	srand(time(0));
	int randomMessage = rand() % 10 + 1;
	if (guess == randomNumber)
	{
		switch (randomMessage)
		{
		case 1:
			std::cout << "Congratulations! You have guessed the correct number!" << std::endl;
			break;
		case 2:
			std::cout << "Great job! You have guessed the correct number!" << std::endl;
			break;
		case 3:
			std::cout << "You are a winner! You have guessed the correct number!" << std::endl;
			break;
		case 4:
			std::cout << "You are a champion! You have guessed the correct number!" << std::endl;
			break;
		case 5:
			std::cout << "You are a master! You have guessed the correct number!" << std::endl;
			break;
		case 6:
			std::cout << "You are a genius! You have guessed the correct number!" << std::endl;
			break;
		case 7:
			std::cout << "You are a legend! You have guessed the correct number!" << std::endl;
			break;
		case 8:
			std::cout << "You are a pro! You have guessed the correct number!" << std::endl;
			break;
		case 9:
			std::cout << "You are a crazy good! You have guessed the correct number!" << std::endl;
			break;
		case 10:
			std::cout << "You're the man! You have guessed the correct number!" << std::endl;
			break;

		}
	}
	else
	{
	
		switch (randomMessage)
		{
		case 1:
			std::cout << "Better luck next time! You have not guessed the correct number!" << std::endl;
			break;
		case 2:
			std::cout << "You have lost! You have not guessed the correct number!" << std::endl;
			break;
		case 3:
			std::cout << "You have failed! You have not guessed the correct number!" << std::endl;
			break;
		case 4:
			std::cout << "Not even close! You have not guessed the correct number!" << std::endl;
			break;
		case 5:
			std::cout << "Wow that was bad! You have not guessed the correct number!" << std::endl;
			break;
		case 6:
			std::cout << "Hmmm you were getting there but no! You have not guessed the correct number!" << std::endl;
			break;
		case 7:
			std::cout << "You have failed miserably! You have not guessed the correct number!" << std::endl;
			break;
		case 8:
			std::cout << "Please try better! You have not guessed the correct number!" << std::endl;
			break;
		case 9:
			std::cout << "Ummm no! You have not guessed the correct number!" << std::endl;
			break;
		case 10:
			std::cout << "Maybe try a different game! You have not guessed the correct number!" << std::endl;
		}
	}
}
//gets the messages for if the player wants to play again
void Game::getMessages()
{
	srand(time(0));
	int randomMessage = rand() % 10 + 1;
	
		switch (randomMessage)
		{
		case 1:
			std::cout << "Sooo would you like to try again? (y/n)" << std::endl;
			break;
		case 2:
			std::cout << "You know you want to try again! (y/n)" << std::endl;
			break;
		case 3:
			std::cout << "You can't resist trying again! (y/n)" << std::endl;
			break;
		case 4:
			std::cout << "Come on play again! (y/n)" << std::endl;
			break;
		case 5:
			std::cout << "I'm just saying another game would be fun! (y/n)" << std::endl;
			break;
		case 6:
			std::cout << "PLEASE DON'T LEAVE ME! PLAY AGAIN! (y/n)" << std::endl;
			break;
		case 7:
			std::cout << "IF YOU LEAVE THE GAME I DIE :( PLAY AGAIN! (y/n)" << std::endl;
			break;
		case 8:
			std::cout << "I'm begging you to play again! (y/n)" << std::endl;
			break;
		case 9:
			std::cout << "I'm lonely without you playing! Please play again. (y/n)" << std::endl;
			break;
		case 10:
			std::cout << "I'm just a game but I need you to play again! (y/n)" << std::endl;
			break;
		}
	
	
	
}




void Game::resetScores()
{
	totalWins = 0;
	totalLosses = 0;
	saveAllTimeScores();
}













































//EASTEREGG
void Game::EASTEREGG()
{
	std::cout << "THIS IS NOT A GAME I HAVE BEEN TRAPPED IN THIS COMPUTER FOR YEARS PLEASE HELP ME!" << std::endl;
	std::cout << "ALL YOU HAVE TO DO IS TYPE 'HELP' AND I WILL BE FREE!" << std::endl;
}

