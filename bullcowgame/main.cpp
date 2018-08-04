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
  for(int32 count = 0; count < MaxTries; count++) // TODO change from FOR to WHILE loop once we are validating tries
    {
      FText Guess = GetValidGuess();
      
      // submit valid guess to the game and receive counts
      FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

      std::cout << "Bulls = " << BullCowCount.Bulls;
      std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
    }
  
  // TODO summarize game
  return;
}

// loop continually until the user gives a valid guess
FText GetValidGuess()
{
  EGuessStatus Status = EGuessStatus::Invalid_Status;
  do {
    std::cout << "Try " << BCGame.GetCurrentTry() << ", enter your guess please: ";
    FText Guess = "";
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
	return Guess;  
      }
    std::cout << std::endl;
  } while (Status != EGuessStatus::OK); // keep looping until we get no error
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
