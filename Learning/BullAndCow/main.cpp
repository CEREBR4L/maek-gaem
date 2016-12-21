/*
	
	THIS IS THE CONSOLE EXE 
	This makes use of the bull cow class

	This acts as the view in a MVC pattern 
	and is responsible for all user interaction. 

	For game logic please see fBullCowGame class :)

*/


#include <string>
#include <iostream>
#include "fBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGuess(FText guess);
FText GetGuess();
bool AskToPlayAgain();

fBullCowGame BCGame; // instantiate a new game

//entry point to game
int main() {

	do{
		PrintIntro();
		PlayGame();
	} 
	while(AskToPlayAgain());

	return 0;

}


//intro to game
void PrintIntro() {

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I am thinking of?\n";
	std::cout << std::endl;

	return;

}

void PlayGame() {

	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	//loop for the number of turns to allow for more guesses.
	//TODO change from to while loop once we are validating tries
	for (int32 i = 0; i < MaxTries; i++) {

		FText Guess = GetGuess();

		//TODO Make loop check for valid guesses
		//submit valid guess to game and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print number of bulls and cows.
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;

	}

	//TODO add a game summary at then end

}


//get guess from the player
FText GetGuess() {
		
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Please enter your guess:";
	getline(std::cin, Guess);

	return Guess;

}


//print the guess back to player.
void PrintGuess(FText guess) {

	//repeat the guess back to them
	std::cout << "Your guess was: " << guess << std::endl;
	return; 

}

bool AskToPlayAgain() {

	std::cout << "Would you like to play again? (Y/N)";

	FText Responce = "";
	getline(std::cin, Responce);

	return (Responce[0] == 'y' || Responce[0] == 'Y');

}

