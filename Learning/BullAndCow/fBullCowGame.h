#pragma once
#include <string>

class fBullCowGame {

public:
	void Reset(); // todo make a more rich return vlaue
	int GetMaxTries();
	int GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValid(std::string);


private:
	int MyCurrentTry = 1;
	int MyMaxTries = 5; 

};
