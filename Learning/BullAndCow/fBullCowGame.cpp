#pragma once

#include "fBullCowGame.h"
#include <iostream>

#include <map>
#define TMap std::map //UE4 Syntax

using int32 = int; //UE4 Syntax

//constructor and getters!
fBullCowGame::fBullCowGame() { Reset(); }
int32 fBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 fBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool fBullCowGame::IsGameWon() const { return bGameWon; }


int32 fBullCowGame::GetMaxTries() const {

	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 7}, {5, 9}, {6, 13}, {7, 18} };
	return WordLengthToMaxTries[MyHiddenWord.length()];

}


void fBullCowGame::Reset() {

	const FString HIDDEN_WORD = "planet"; //this MUST be a isogram
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameWon = false;
	return;

}


eGuessStatus fBullCowGame::CheckGuessValid(FString Guess) const{

	if (!IsIsogram(Guess)) {
		return eGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
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

bool fBullCowGame::IsIsogram(FString Word) const {

	//treat 0/1 letter strings as isograms
	if (Word.length() < 2) {
		return true;
	}

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word){ //loop through word
		
		Letter = tolower(Letter); // handle mixed case
		
		if (LetterSeen[Letter]) {
			return false; 
		}
		else {
			LetterSeen[Letter] = true; //add to map
		}

	}

	return true;

}

bool fBullCowGame::IsLowercase(FString Word) const {

	for (auto Letter : Word) {

		if (!islower(Letter)) {
			return false;
		}

	}

	return true;

}

