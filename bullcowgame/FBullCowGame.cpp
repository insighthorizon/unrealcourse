#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
  constexpr int32 MAX_TRIES = 8;

  MyMaxTries = MAX_TRIES;
  MyCurrentTry = 1;  
  return;
}
int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::SetGuess(FString)
{
  return;
}
bool FBullCowGame::CheckGuessValidity(FString)
{
  return false;
}
void FBullCowGame::AnalyseGuess()
{
  return;
}

int32 FBullCowGame::GetBulls() const { return 0; }
int32 FBullCowGame::GetCows() const { return 0; }

bool FBullCowGame::IsGameOver() const { return false; }
bool FBullCowGame::IsGameWon() const { return false; }
bool FBullCowGame::IsGameLost() const { return false; }
int32 FBullCowGame::GetHint()
{
  return 0;
}
