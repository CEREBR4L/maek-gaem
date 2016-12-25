/*
The game logic, no direct user interaction
A simple guess the word game
*/

#pragma once
#include <string>

//UE4 Syntax
using FString = std::string;
using int32 = int;

struct FBullCowCount {

	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class eGuessStatus {

	Invalid_Status,
	OK,
	Not_Isogram,
	Incorrect_Length,
	Not_Lowercase

};

class fBullCowGame {

public:
	fBullCowGame(); //constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	eGuessStatus CheckGuessValid(FString) const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	//initilised in contstructor
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameWon;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;

};
