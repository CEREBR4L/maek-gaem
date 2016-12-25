/*
	
	THIS IS THE CONSOLE EXE 
	This makes use of the bull cow class

	This acts as the view in a MVC pattern 
	and is responsible for all user interaction. 

	For game logic please see fBullCowGame class :)

*/

#pragma once

#include <string>
#include <iostream>
#include "fBullCowGame.h"

//UE4 syntax
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGuess(FText guess);
FText GetValidGuess();
bool AskToPlayAgain();
FString PrintGameSummary();

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


void PrintIntro() {

	std::cout << std::endl << std::endl;
	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }   {         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I am thinking of?\n";
	std::cout << std::endl;

	return;

}

void PlayGame() {

	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();

	//loop asking for a guess while the game is NOT WON and there is tries left
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){

		FText Guess = GetValidGuess();

		//submit valid guess to game and recieve counts
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << " Cows = " << BullCowCount.Cows << std::endl << std::endl;

	}

	std::cout << PrintGameSummary() << std::endl << std::endl;
	return;

}


//loop until there is a valid guess
FText GetValidGuess() {

	FText Guess = "";
	eGuessStatus Status = eGuessStatus::Invalid_Status;
	bool GameWon = BCGame.IsGameWon();

	do {

		int32 CurrentTry = BCGame.GetCurrentTry();

		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries() << ".";
		std::cout << " Enter your guess : ";
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValid(Guess);
		switch (Status) {

			case eGuessStatus::Incorrect_Length:
				std::cout << "Please a " << BCGame.GetHiddenWordLength() << " letter word!" << std::endl << std::endl;
				break;

			case eGuessStatus::Not_Isogram:
				std::cout << "Please enter a valid Isogram (a word without repeating letters)!" << std::endl << std::endl;
				break;

			case eGuessStatus::Not_Lowercase:
				std::cout << "Please make sure you enter the word in lowercase." << std::endl << std::endl;
				break;

			default:
				//assume guess valid
				break;
		}

	} while (Status != eGuessStatus::OK); //keep looping until a valid guess

	return Guess;

}


void PrintGuess(FText guess) {

	//repeat the guess back to them
	std::cout << "Your guess was: " << guess << std::endl;
	return; 

}

bool AskToPlayAgain() {

	std::cout << "Would you like to play again with the same hidden word? (Y/N)";

	FText Responce = "";
	getline(std::cin, Responce);

	return (Responce[0] == 'y' || Responce[0] == 'Y');

}

FString PrintGameSummary() {

	if (BCGame.IsGameWon()) {
		return "Well DONE, YOU WIN!";
	}
	else {
		return "BETTER LUCK NEXT TIME!";
	}

}

