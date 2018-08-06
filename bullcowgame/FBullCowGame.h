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
struct FRange
{
  int32 Min = 0;
  int32 Max = 0;
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
  void Reset();
  
  int32 GetMaxTries() const; // const makes sure function doesn't change anything
  int32 GetCurrentTry() const;
  FRange GetLengthRange() const;    
  int32 GetHiddenWordLength() const;
  EGuessStatus CheckGuessValidity(FString) const;
  bool IsGameWon() const;

  void SetValidWordLength(int32);
  FBullCowCount SubmitValidGuess(FString);
  
  
 private:
  int32 WordLength;
  TMap<int32, FString> LengthToHiddenWord;
  TMap<int32, int32> WordLengthToMaxTries;  
  int32 MyCurrentTry;
  bool bGameIsWon;

  bool IsIsogram(FString) const;
  bool IsLowercase(FString) const;
};
