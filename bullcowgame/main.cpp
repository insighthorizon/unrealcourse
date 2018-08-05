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
FText GetValidGuess();
void PrintGuessBack(FText Guess);
void PrintGameSummary();
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
  std::cout << "\n\nWelcome to Bulls and Cows, a fun word game." << std::endl;
  std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
  std::cout << " letter isogram I'm thinking of?" << std::endl;
  std::cout << std::endl;
  return;
}

void PlayGame()
{
  BCGame.Reset();
  int32 MaxTries = BCGame.GetMaxTries();
  
  // loop asking for guesses while the game
  // is NOT won and there are still tries remaining
  while ( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries ) // TODO change from FOR to WHILE
    {
      FText Guess = GetValidGuess();
      
      // submit valid guess to the game and receive counts
      FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

      std::cout << "Bulls = " << BullCowCount.Bulls;
      std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
    }
  
  PrintGameSummary();

  return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
  FText Guess = "";
  EGuessStatus Status = EGuessStatus::Invalid_Status;
  do {
    std::cout << "Try " << BCGame.GetCurrentTry() << ", enter your guess please: ";
    getline(std::cin, Guess); //  get a guess from the player
    Status = BCGame.CheckGuessValidity(Guess);
    
    switch (Status)
      {
      case EGuessStatus::Wrong_Length:
	std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
	break;
      case EGuessStatus::Not_Isogram:
	std::cout << "Please enter a word without repeating letters.\n";
	break;
      case EGuessStatus::Not_Lowercase:
	std::cout << "Please enter only lowercase characters.\n";      
	break;
      default:
	{ /* assume the guess is valid */  }
      }
    std::cout << std::endl;
  } while (Status != EGuessStatus::OK); // keep looping until we get no error
  return Guess;  
}

void PrintGameSummary()
{
  if (BCGame.IsGameWon()) { std::cout << "WELL DONE - YOU WIN!\n\n"; }
  else { std::cout << "Bettern luck next time!\n\n"; }
  return;
}

bool AskToPlayAgain()
{
  FText Response = "";
  while(Response[0] != 'y' && Response[0] != 'Y' && Response[0] != 'n' && Response[0] != 'N')
    {
      std::cout << "Do you want to play again with the same hidden word (y/n)? ";
      getline(std::cin, Response);
    }
  
  return (Response[0] == 'y') || (Response[0] == 'Y');
}

