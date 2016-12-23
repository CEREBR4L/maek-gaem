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

	return bGameWon;

}


void fBullCowGame::Reset() {

	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameWon = false;
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
FBullCowCount fBullCowGame::SubmitValidGuess(FString Guess) {
	
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); //assume same lenght of guess

	for(int32 i = 0; i < WordLength; i++) {

		for(int32 j = 0; j < WordLength; j++) {

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

	if(BullCowCount.Bulls == WordLength){

		bGameWon = true;

	}
	else {

		bGameWon = false;

	}
	
	return BullCowCount;

}

