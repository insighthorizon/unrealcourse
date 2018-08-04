#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }
void FBullCowGame::Reset()
{
  constexpr int32 MAX_TRIES = 3;
  const FString HIDDEN_WORD = "planet";
  
  MyMaxTries = MAX_TRIES;
  MyHiddenWord = HIDDEN_WORD;  
  MyCurrentTry = 1;
  return;
}
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

// receives a VALID guess, increments turn number and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
  // increment the turn number
  MyCurrentTry++;
  // setup a return variable
  FBullCowCount BullCowCount;
  // loop through all letters in the guess
  int32 HiddenWordLength = MyHiddenWord.length();
  for (int32 GChar = 0; GChar < HiddenWordLength; GChar++)
    {   
     // compare letters againts the hidden word
     // if they match then
      if (Guess[GChar] ==  MyHiddenWord[GChar]) // increment bulls if they're in the same place      
	{
	  BullCowCount.Bulls++;
	}
      else
	{
	for (int32 HChar = 0; HChar < HiddenWordLength; HChar++)
	  {
	    if (Guess[GChar] == MyHiddenWord[HChar]) // increment cows if they're not in the same place
	      {
		BullCowCount.Cows++;
	      }
	  }
	}
    }
  return BullCowCount;
}

void FBullCowGame::SetGuess(FString)
{
  return;
}
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
  if (false) // if the guess isn't an isogram
    {
      return EGuessStatus::Not_Isogram;
    }
  else if (false) // if the guess isn't all lowercase
    {
      return EGuessStatus::Not_Lowercase;
    }
  else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong
    {
      return EGuessStatus::Wrong_Length;
    }
  else // otherwise
    {
      return EGuessStatus::OK;
    }
}

void FBullCowGame::AnalyseGuess()
{
  return;
}

int32 FBullCowGame::GetBulls() const { return 0; }
int32 FBullCowGame::GetCows() const { return 0; }

bool FBullCowGame::IsGameOver() const { return false; }
bool FBullCowGame::IsGameWon() const { return false; }
bool FBullCowGame::IsGameLost() const { return false; }
int32 FBullCowGame::GetHint()
{
  return 0;
}
