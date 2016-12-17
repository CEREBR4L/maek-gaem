
#include <string>
#include <iostream>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
void PrintGuess(string guess);

//entry point to game
int main(){

	PrintIntro();
	PlayGame();

	return 0;

}


//intro to game
void PrintIntro() {

	constexpr int WORD_LENGTH = 9;

	cout << "Welcome to Bulls and Cows, a fun word game.\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I am thinking of?\n";
	cout << endl;

	return;

}

void PlayGame() {

	constexpr int NUM_OF_GUEESES = 5;

	//loop for the number of turns to allow for more guesses.
	for (int i = 0; i < NUM_OF_GUEESES; i++) {

		PrintGuess(GetGuess());
		cout << endl;

	}

}


//get guess from the player
string GetGuess() {
		
	string Guess = "";

	cout << "Please enter your guess:";
	getline(cin, Guess);

	return Guess;

}


//print the guess back to player.
void PrintGuess(string guess) {

	//repeat the guess back to them
	cout << "Your guess was: " << guess << endl;
	return; 

}
