#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }
void FBullCowGame::Reset()
{
  constexpr int32 MAX_TRIES = 3;
  const FString HIDDEN_WORD = "planet";

  bGameIsWon = false;
  MyMaxTries = MAX_TRIES;
  MyHiddenWord = HIDDEN_WORD;  
  MyCurrentTry = 1;
  return;
}
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

// receives a VALID guess, increments turn number and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
  MyCurrentTry++;
  FBullCowCount BullCowCount;
  int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

  // loop through all letters in the guess 
  for (int32 GChar = 0; GChar < WordLength; GChar++)
    {   
     // compare letters againts the hidden word
      if (Guess[GChar] ==  MyHiddenWord[GChar])
	{
	  BullCowCount.Bulls++;
	}
      else
	{ // compare letter of guess to all letters of hidden word
	for (int32 HChar = 0; HChar < WordLength; HChar++)
	  {
	    if (Guess[GChar] == MyHiddenWord[HChar])
	      {
		BullCowCount.Cows++;
	      }
	  }
	}
    }
  if (BullCowCount.Bulls == WordLength) { bGameIsWon = true;} // condition for winning the game
  else { bGameIsWon = false; }
  return BullCowCount;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
  if (false) // if the guess isn't an isogram
    {
      return EGuessStatus::Not_Isogram; // TODO write function
    }
  else if (false) // if the guess isn't all lowercase
    {
      return EGuessStatus::Not_Lowercase; // TODO write function
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




int32 FBullCowGame::GetHint()
{
  return 0;
}
