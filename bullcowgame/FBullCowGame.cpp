#include "FBullCowGame.h"
#include <map>
#include <iostream>


// to make syntax Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); } // class constructor
void FBullCowGame::Reset()
{
  // These words must be isograms
  LengthToHiddenWord = { {3,"ant"} , {4,"plot"}, {5,"brute"}, {6,"planet"}, {7, "gearbox"}, {8, "keyboard"}, {9, "pneumatic"}, {10, "aftershock"} };
  WordLengthToMaxTries = { {3,5}, {4,7}, {5,10}, {6,16}, {7, 17}, {8, 18}, {9, 18}, {10, 19} };  

  WordLength = 5;
  bGameIsWon = false;
  MyCurrentTry = 1;
  return;
}


int32 FBullCowGame::GetMaxTries() const { return WordLengthToMaxTries.at(WordLength); }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
FRange FBullCowGame::GetLengthRange() const
{
  FRange range;
  range.Min = LengthToHiddenWord.begin()->first;
  range.Max = LengthToHiddenWord.rbegin()->first;
  return range;
}
int32 FBullCowGame::GetHiddenWordLength() const { return WordLength; }
EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
  if (!IsIsogram(Guess))
    {
      return EGuessStatus::Not_Isogram;
    }
  else  if (!IsLowercase(Guess))
    {
      return EGuessStatus::Not_Lowercase;
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
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


void FBullCowGame::SetValidWordLength(int32 lol)
{
  WordLength = lol;
  return;
}
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
  MyCurrentTry++;
  FBullCowCount BullCowCount;

  FString MyHiddenWord = LengthToHiddenWord.at(WordLength);

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
  if (BullCowCount.Bulls == WordLength) { bGameIsWon = true;}
  else { bGameIsWon = false; }
  return BullCowCount;
}


bool FBullCowGame::IsIsogram(FString Word) const
{
  // treat 0 and 1 letter words as isograms
  if (Word.length() <= 1) { return true; }

  // create table of characters and their occurance
  TMap<char, bool> LetterSeen;
  
  for (auto Letter : Word)
    {
      Letter = tolower(Letter); // handle mixed case
      
      if (LetterSeen[Letter]) { return false; }
      else { LetterSeen[Letter] = true; }
    }
    return true;
}
bool FBullCowGame::IsLowercase(FString Word) const
{
  if (Word.length() <= 1) {
    if (Word.length() == 0 || Word[0] == ' ') { return true; }
  }

  for (auto Letter: Word)
    {
      if (!islower(Letter)) { return false; }
    }
  return true;
}
