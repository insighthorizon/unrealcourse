#pragma once

class FBullCowGame
{
 public:
  void Reset(); // TODO make a more rich return value
  int GetMaxTries();
  int GetCurrentTry();
  void SetGuess(string);
  bool CheckGuessValidity(string); // TODO make a more rich return value
  void AnalyseGuess();
  int GetBulls();
  int GetCows();
  bool IsGameOver();
  bool IsGameWon();
  bool IsGameLost();
  int GetHint();
  
  // ^^ Please try and ignore this and focus on the interfrace above ^^  
 private:
  int MyCurrentTry;
  int MyMaxTries;
};
