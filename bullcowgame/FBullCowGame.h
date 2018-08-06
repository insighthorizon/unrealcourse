/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind  */
#pragma once

#include <string>
#include <map>

// to make syntax Unreal friendly
#define TMap std::map
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};

enum class EGuessStatus // use class to prevent redeclaration
  {
    Invalid_Status,
      OK,
      Not_Isogram,
      Wrong_Length,
      Not_Lowercase,
      };


class FBullCowGame
{
 public:
  FBullCowGame();
  void Reset(); // TODO make a more rich return value
  void SetValidDifficulty();
  
  int32 GetMaxTries() const; // const makes sure function doesn't change anything
  int32 GetCurrentTry() const;
  int32 GetHiddenWordLength() const;
  bool IsGameWon() const;    
  EGuessStatus CheckGuessValidity(FString) const;
  FBullCowCount SubmitValidGuess(FString);
  
  int32 GetHint();
  
 private:
  int32 difficulty;
  TMap<int32, FString> LengthToHiddenWord;


  int32 MyCurrentTry;
  bool bGameIsWon;

  bool IsIsogram(FString) const;
  bool IsLowercase(FString) const;
};
