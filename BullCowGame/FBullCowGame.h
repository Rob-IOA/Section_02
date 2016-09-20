#pragma once

#include <string>

using FString = std::string;
using int32 = int;

// Two integers, both initialised to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status, // The word hasn't been validated yet
	OK,  // The word is a lower case isogram of the correct length
	Not_Word, // The word isn't actually a word
	Not_Lowercase, // The word doesn't consist of entirely lower case letters
	Not_Isogram,  // The word is not an isogram
	Wrong_Length // The word is not the same length as the hidden word
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	FBullCowCount SubmitValidGuess(FString); // evaluate player's validated guess and increase try number
	void Reset();  // TODO Make a more rich return value

// Ignore for now
private:
	int32 MyCurrentTry;
	int32 MyMaxTries;

	FString MyHiddenWord;
};