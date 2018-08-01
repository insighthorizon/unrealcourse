#include <iostream> // to get access to cout, std::cin methods and << operator
#include <string> // to get acces to >> operator
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
void PrintGuessBack(std::string Guess);
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
  constexpr int WORD_LENGTH = 5;
  std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
  std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << std::endl;
  std::cout << std::endl;
  return;
}

void PlayGame()
{
  int MaxTries = BCGame.GetMaxTries();
  
  /* loop for the number of turns asking for guesses */
  std::string Guess = "";
  for(int count = 0; count < MaxTries; count++)
    {
      Guess = GetGuess();
      PrintGuessBack(Guess);
      std::cout << std::endl;
    }
  return;
}

/* get a guess from the player */
std::string GetGuess()
{
  std::string Guess = "";
  std::cout << "Try " << BCGame.GetCurrentTry() << ", enter your guess please: ";
  getline(std::cin, Guess);
  return Guess;
}

/* reapeat guess back to player */
void PrintGuessBack(std::string Guess)
{
  std::cout << "Here is your guess: " << Guess;
  std::cout << std::endl;
  return;
}

bool AskToPlayAgain()
{
  std::string Response = "";
  while(Response[0] != 'y' && Response[0] != 'Y' && Response[0] != 'n' && Response[0] != 'N')
    {
      std::cout << "Do you want to play again?- yes/no: ";
      getline(std::cin, Response);
    }
  
  return (Response[0] == 'y') || (Response[0] == 'Y');
}
