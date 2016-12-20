#include "fBullCowGame.h"

fBullCowGame::fBullCowGame() {

	Reset();

}


int32 fBullCowGame::GetMaxTries() const {

	return MyMaxTries;

}


int32 fBullCowGame::GetCurrentTry() const {

	return MyCurrentTry;

}


bool fBullCowGame::IsGameWon() const {

	return false;

}


void fBullCowGame::Reset() {

	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "ant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;

}


bool fBullCowGame::CheckGuessValid(FString) {

	return false;

}

//recieves valid guess, increases turn and returns count.
FBullCowCount fBullCowGame::SubmitGuess(FString Guess) {
	
	// increase turn num
	MyCurrentTry++;
	//setup return structure
	FBullCowCount BullCowCount;

	//loop  through all letters in guess
	int32 HiddenWordLength = MyHiddenWord.length();

	for(int32 i = 0; i < HiddenWordLength; i++){

		for(int32 j = 0; j < HiddenWordLength; j++){

			//compare letters against hidden word.
			//if match incriment bulls if in the same place or cows if they are not.
			if (Guess[i] == MyHiddenWord[i]) {

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

