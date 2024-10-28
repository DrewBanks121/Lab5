#include <iostream>
#ifndef Game_H
#define Game_H

class Game
{
public:
	Game();
	~Game();
	void playGame();
	void getAllTimeScores();
	void saveAllTimeScores();
	void displayAllTimeScores();
	void getMessagesWinlost();
	void getMessages();
	void EASTEREGG();

private:
	bool canPlay = true;
	int guess = 0;
	int randomNumber = 0;
	int maxGuesses = 0;
	int amountOfGuesses = 0;
	std::string playAgain = " ";
	float totalWins = 0;
	float totalLosses = 0;
	bool EASTEREGGbool = false;
};


#endif // !Game_H

