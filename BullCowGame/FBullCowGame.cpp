#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame()
{
	Reset();
}


int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
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
	return false;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Word;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (false)
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

	// TODO don't think this belongs here...
	// Increment the current turn number
	MyCurrentTry++;

	return BullCowCount;
}


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet";
	constexpr int32 MAX_TRIES = 8;

	MyHiddenWord = HIDDEN_WORD;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	return;
}
