#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// Entry point
int main()
{
	bool bPlayAgain = false;

	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	return 0;  // Exit the game
}


// Introduce the game
void PrintIntro()
{
	// The length of the word to be guessed
	constexpr int WORD_LENGTH = 9;

	cout << "Welcome to Bulls and Cows, a fun word game." << endl;
	cout << "Can you guess the " << WORD_LENGTH << "-letter isogram I'm thinking of?" << endl;
	cout << endl;

	return;
}


void PlayGame()
{
	// The number of guesses the player is allowed
	constexpr int NUMBER_OF_GUESSES = 5;

	// Loop through the number of guesses allowed
	for (int Attempt = 1; Attempt <= NUMBER_OF_GUESSES; Attempt++)
	{
		// The player's guess
		string Guess = GetGuess();
		cout << "You guessed: " << Guess << endl;
		cout << endl;
	}

}


// Get a guess from the player
string GetGuess()
{
	cout << "Enter your guess: ";

	// The player's guess
	string Guess = "";

	// Get a string from the console input
	getline(cin, Guess);

	return Guess;
}


bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)? ";
	string Response = "";
	getline(cin, Response);
	cout << endl;

	return ((Response[0] == 'y') || (Response[0] == 'Y'));  // Anything other than something starting with 'y' (case-insensitive) will return false
}
