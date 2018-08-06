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

  difficulty = 5;
  bGameIsWon = false;
  MyCurrentTry = 1;
  return;
}

// i fucked up here, the function has side effetcs of cin and cout, but i'm not willing to rework everything just for that
void FBullCowGame::SetValidDifficulty()
{
  constexpr int32 MIN_LENGTH = 3;
  constexpr int32 MAX_LENGTH = 10;

  difficulty = 0;
  FString input = "";
  while ( (difficulty > 10) || (difficulty < 3) )
    {
      difficulty = 0;
      std::cout << "Please choose length of hidden isogram between 3 and 10: ";
      getline(std::cin, input);

      int32 exp = 1;
       for (auto letter : input)
	{
	  if ( letter > '9' || letter < '0') { difficulty = 0; break; }
	  difficulty += exp*(letter - '0');
	  exp = 10*exp;
	}

    }
  std::cout << "\nGuess the  " << difficulty << " letter hidden word!\n";
  return;
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return difficulty; }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }


int32 FBullCowGame::GetMaxTries() const
{
  TMap<int32, int32> WordLengthToMaxTries{ {3,5}, {4,7}, {5,10}, {6,16}, {7, 17}, {8, 18}, {9, 18}, {10, 19} };
  return WordLengthToMaxTries[difficulty];
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
  MyCurrentTry++;
  FBullCowCount BullCowCount;

  FString MyHiddenWord = LengthToHiddenWord[difficulty];

  for (int32 GChar = 0; GChar < difficulty; GChar++)
    {   
     // compare letters againts the hidden word
      if (Guess[GChar] ==  MyHiddenWord[GChar])
	{
	  BullCowCount.Bulls++;
	}
      else
	{ // compare letter of guess to all letters of hidden word
	for (int32 HChar = 0; HChar < difficulty; HChar++)
	  {
	    if (Guess[GChar] == MyHiddenWord[HChar])
	      {
		BullCowCount.Cows++;
	      }
	  }
	}
    }
  if (BullCowCount.Bulls == difficulty) { bGameIsWon = true;}
  else { bGameIsWon = false; }
  return BullCowCount;
}


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




int32 FBullCowGame::GetHint()
{
  return 0;
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
