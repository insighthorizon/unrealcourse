#pragma once
#include <string>

class FBullCowGame
{
 public:
  FBullCowGame(); // constructor
  void Reset(); // TODO make a more rich return value
  int GetMaxTries() const; // const prevents this function from having functionality of changing any member variables (MyCurrentTry, MyMaxTries...) - for safety
  int GetCurrentTry() const;
  void SetGuess(std::string);
  bool CheckGuessValidity(std::string); // TODO make a more rich return value
  void AnalyseGuess();
  int GetBulls() const;
  int GetCows() const;
  bool IsGameOver() const;
  bool IsGameWon() const;
  bool IsGameLost() const;
  int GetHint();
  
  // ^^ Please try and ignore this and focus on the interfrace above ^^  
 private:
  // see constructor for initialization
  int MyCurrentTry;
  int MyMaxTries;
};
