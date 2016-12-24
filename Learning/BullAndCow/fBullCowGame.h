#pragma once
#include <string>

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

	void Reset(); // todo make a more rich return vlaue

	FBullCowCount SubmitValidGuess(FString);

private:
	//initilised in contstructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameWon;

	bool IsIsogram(FString) const;

};
