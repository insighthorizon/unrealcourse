#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
  constexpr int MAX_TRIES = 8;

  MyMaxTries = MAX_TRIES;
  MyCurrentTry = 1;  
  return;
}
int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::SetGuess(std::string)
{
  return;
}
bool FBullCowGame::CheckGuessValidity(std::string)
{
  return false;
}
void FBullCowGame::AnalyseGuess()
{
  return;
}

int FBullCowGame::GetBulls() const { return 0; }
int FBullCowGame::GetCows() const { return 0; }

bool FBullCowGame::IsGameOver() const { return false; }
bool FBullCowGame::IsGameWon() const { return false; }
bool FBullCowGame::IsGameLost() const { return false; }
int FBullCowGame::GetHint()
{
  return 0;
}
