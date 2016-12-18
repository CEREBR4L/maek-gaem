
#include <string>
#include <iostream>

void PrintIntro();
void PlayGame();
void PrintGuess(std::string guess);
std::string GetGuess();
bool AskToPlayAgain();

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

	constexpr int WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I am thinking of?\n";
	std::cout << std::endl;

	return;

}

void PlayGame() {

	constexpr int NUM_OF_GUEESES = 5;

	//loop for the number of turns to allow for more guesses.
	for (int i = 0; i < NUM_OF_GUEESES; i++) {

		PrintGuess(GetGuess());
		std::cout << std::endl;

	}

}


//get guess from the player
std::string GetGuess() {
		
	std::string Guess = "";

	std::cout << "Please enter your guess:";
	getline(std::cin, Guess);

	return Guess;

}


//print the guess back to player.
void PrintGuess(std::string guess) {

	//repeat the guess back to them
	std::cout << "Your guess was: " << guess << std::endl;
	return; 

}

bool AskToPlayAgain() {

	std::cout << "Would you like to play again? (Y/N)";

	std::string Responce = "";
	getline(std::cin, Responce);

	return (Responce[0] == 'y' || Responce[0] == 'Y');

}

