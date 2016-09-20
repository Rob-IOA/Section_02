#include <iostream>
#include <string>

#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();

// The game object
FBullCowGame BCGame;

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
	std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << "-letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;

	return;
}


void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	// Loop through the number of guesses allowed
	// TODO change to while loop to handle exit conditions
	for (int32 Attempt = 1; Attempt <= MaxTries; Attempt++)
	{
		// The player's guess
		FText Guess = GetValidGuess();

		// The result of checking the player's guess
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ", ";
		std::cout << "Cows = " << BullCowCount.Cows;
		std::cout << std::endl;

		std::cout << std::endl;
	}

	// TODO add a game summary

	return;
}


// Get a validated guess from the player
FText GetValidGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	// The player's guess
	FText Guess = "";
	EGuessStatus GuessStatus = EGuessStatus::Invalid_Status;

	do
	{
		std::cout << "Try " << CurrentTry << ". ";
		std::cout << "Enter your guess: ";

		// Get a string from the console input
		getline(std::cin, Guess);

		// The validation status of the player's guess
		GuessStatus = BCGame.CheckGuessValidity(Guess);

		switch (GuessStatus)
		{
		case EGuessStatus::Not_Word:
			std::cout << "Please enter a single word" << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lower case word" << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter an isogram (all letters must be different)" << std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << "-letter word" << std::endl;
			break;
		default:
			break;
		}

		std::cout << std::endl;
	} while (GuessStatus != EGuessStatus::OK);

	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl;

	return ((Response[0] == 'y') || (Response[0] == 'Y'));  // Anything other than something starting with 'y' (case-insensitive) will return false
}
