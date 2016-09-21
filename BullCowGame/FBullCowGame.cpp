#pragma once

#include "FBullCowGame.h"

#include <map>

// Substitutions to match Unreal Engine standards
#define TMap std::map
using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame()
{
	Reset();
}


int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3, 4}, {4, 7}, {5, 10}, {6, 16}, {7, 20} };

	return WordLengthToMaxTries[MyHiddenWord.length()];
}


int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}


bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsWord(Guess))
	{
		return EGuessStatus::Not_Word;
	}
	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}


FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	// A variable to hold the result (the number of bulls and cows)
	FBullCowCount BullCowCount;

	// The length in characters of the hidden word
	int32 WordLength = GetHiddenWordLength();
	
	// Loop through each character in the guess
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		for (int32 GChar = 0; GChar < WordLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar]) // If the character appears in the hidden word
			{
				if (MHWChar == GChar) // and in the same position, add 1 to the bulls count
				{
					BullCowCount.Bulls++;
				}
				else // but not in the same position, add 1 to the cows count
				{
					BullCowCount.Cows++;
				}
			}
			else // Do nothing
			{
			}
		}
	}

	bGameIsWon = (BullCowCount.Bulls == WordLength);

	// Increment the current turn number
	MyCurrentTry++;

	return BullCowCount;
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";

	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}


bool FBullCowGame::IsWord(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!isalpha(Letter))
		{
			return false;
		}
	}

	return true;
}


bool FBullCowGame::IsLowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!isalpha(Letter))
		{
			return false;
		}
		else if (!islower(Letter))
		{
			return false;
		}
	}

	return true;
}


bool FBullCowGame::IsIsogram(FString Word) const
{
	// Hash table for tracking duplicated letters
	TMap<char, bool> LetterSeen;

	if (!IsWord(Word))
	{
		return false;
	}

	// Loop through each character in the word (boundary cases of empty string and single character both OK with this approach, i.e., will return true)
	for (auto Letter : Word)
	{
		Letter = tolower(Letter);

		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
	}

	// If we haven't left the function early then it is an isogram
	return true;
}
