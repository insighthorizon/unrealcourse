#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
  int32 Bulls = 0; // all values initialized to zero
  int32 Cows = 0;
};

enum class EGuessStatus // use class to prevent redeclaration (for example OK)
{
  OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase,
};


class FBullCowGame
{
 public:
  FBullCowGame(); // constructor
  void Reset(); // TODO make a more rich return value
  int32 GetMaxTries() const; // const prevents this function from having functionality of changing any member variables (MyCurrentTry, MyMaxTries...) - for safety
  int32 GetCurrentTry() const;
  int32 GetHiddenWordLength() const;
  void SetGuess(FString);
  EGuessStatus CheckGuessValidity(FString) const;
  FBullCowCount SubmitGuess(FString);
  
  void AnalyseGuess();
  int32 GetBulls() const;
  int32 GetCows() const;
  bool IsGameOver() const;
  bool IsGameWon() const;
  bool IsGameLost() const;
  int32 GetHint();



  
  // ^^ Please try and ignore this and focus on the interfrace above ^^  
 private:
  // see constructor for initialization
  int32 MyCurrentTry;
  int32 MyMaxTries;
  FString MyHiddenWord;
};
