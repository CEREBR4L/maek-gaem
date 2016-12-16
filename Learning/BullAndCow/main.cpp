
#include <string>
#include <iostream>

using namespace std;

void PrintIntro();
string GetGuess();
void PrintGuess(string guess);

//entry point to game
int main(){

	PrintIntro();
	PrintGuess(GetGuess());

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


//get guess from the player
string GetGuess() {
		
	string Guess = "";

	cout << "Please enter your guess:";
	getline(cin, Guess);

	return Guess;

}

void PrintGuess(string guess) {

	//repeat the guess back to them
	cout << "Your guess was: " << guess << endl;
	return; 

}
