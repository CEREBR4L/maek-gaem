#include "fBullCowGame.h"
#include <iostream>

fBullCowGame::fBullCowGame() {

	Reset();

}


int32 fBullCowGame::GetMaxTries() const {

	return MyMaxTries;

}


int32 fBullCowGame::GetCurrentTry() const {

	return MyCurrentTry;

}


int32 fBullCowGame::GetHiddenWordLength() const {

	return MyHiddenWord.length();

}


bool fBullCowGame::IsGameWon() const {

	return false;

}


void fBullCowGame::Reset() {

	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;

}


eGuessStatus fBullCowGame::CheckGuessValid(FString Guess) const{

	if (false) {
		return eGuessStatus::Not_Isogram;
	}
	else if (false) {
		return eGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return eGuessStatus::Incorrect_Length;
	}
	else {
		return eGuessStatus::OK;
	}

}

//recieves valid guess, increases turn and returns count.
FBullCowCount fBullCowGame::SubmitGuess(FString Guess) {
	
	// increase turn num
	MyCurrentTry++;
	//setup return structure
	FBullCowCount BullCowCount;

	//loop  through all letters in guess
	int32 HiddenWordLength = MyHiddenWord.length();

	for(int32 i = 0; i < HiddenWordLength; i++) {

		for(int32 j = 0; j < HiddenWordLength; j++) {

			//compare letters against hidden word.
			//if match incriment bulls if in the same place or cows if they are not.
			if (Guess[j] == MyHiddenWord[i]) {

				if (i == j) {

					BullCowCount.Bulls++;

				}
				else {

					BullCowCount.Cows++;

				}

			}

		}

	}
	
	return BullCowCount;

}

