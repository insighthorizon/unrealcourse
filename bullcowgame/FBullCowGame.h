#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialized to zero
struct BullCowCount
{
  int32 Bulls = 0;
  int32 Cows = 0;
};


class FBullCowGame
{
 public:
  FBullCowGame(); // constructor
  void Reset(); // TODO make a more rich return value
  int32 GetMaxTries() const; // const prevents this function from having functionality of changing any member variables (MyCurrentTry, MyMaxTries...) - for safety
  int32 GetCurrentTry() const;
  void SetGuess(FString);
  bool CheckGuessValidity(FString); // TODO make a more rich return value
  BullCowCount SubmitGuess(FString);
  
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
