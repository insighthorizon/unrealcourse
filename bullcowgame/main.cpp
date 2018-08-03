/* This is the console executable, that makes use of the FBullCowGame class.
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.
 */
#include <iostream> // to get access to cout, std::cin methods and << operator
#include <string> // to get acces to >> operator
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
void PrintGuessBack(FText Guess);
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

/* entry point for our application */
int main()
{
  do
    {
      PrintIntro();
      PlayGame();      
    }
  while(AskToPlayAgain());

  return 0; // exit the application
}


/* introduce the game */
void PrintIntro()
{
  std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
  std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
  std::cout << " letter isogram I'm thinking of?" << std::endl;
  std::cout << std::endl;
  return;
}

void PlayGame()
{
  BCGame.Reset();
  int32 MaxTries = BCGame.GetMaxTries();
  
  /* loop for the number of turns asking for guesses */
  FText Guess = "";
  // TODO change from FOR to WHILE loop once we are validating tries
  for(int32 count = 0; count < MaxTries; count++)
    {
      Guess = GetGuess(); // TODO make loop checking guess validity (dont accept bullshit quess)
      // submit valid guess to the game and receive counts
      FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
      // print number of bulls and cows
      std::cout << "Bulls = " << BullCowCount.Bulls;
      std::cout << " Cows = " << BullCowCount.Cows << std::endl;
      
      std::cout << std::endl;
    }
  // TODO summarize game
  
  return;
}

/* get a guess from the player */
FText GetGuess()
{
  FText Guess = "";
  std::cout << "Try " << BCGame.GetCurrentTry() << ", enter your guess please: ";
  getline(std::cin, Guess);
  return Guess;
}


bool AskToPlayAgain()
{
  FText Response = "";
  while(Response[0] != 'y' && Response[0] != 'Y' && Response[0] != 'n' && Response[0] != 'N')
    {
      std::cout << "Do you want to play again?- yes/no: ";
      getline(std::cin, Response);
    }
  
  return (Response[0] == 'y') || (Response[0] == 'Y');
}
