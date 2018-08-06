/* This is the console executable, that makes use of the FBullCowGame class.
This acts as the view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.
 */

#include <iostream> // to get access to cout, std::cin methods and << operator
#include <string> // to get acces to >> operator
#include "FBullCowGame.h"

// to make syntax Unreal friendly
using FText = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
int32 GetValidWordLength();
FText GetValidGuess();
void PrintGuessBack(FText Guess);
void PrintGameSummary();
bool AskToPlayAgain();


FBullCowGame BCGame; // instantiate a new game, which we re-use across plays


int main()
{
  do
    {
      PrintIntro();
      PlayGame();      
    }
  while(AskToPlayAgain());

  return 0;
}


void PrintIntro()
{

  const char asciiArt[] = "  ____        _ _                              \n"
" |  _ \\      | | |                             \n"
" | |_) |_   _| | |___                          \n"
" |  _ <| | | | | / __|                         \n"
" | |_) | |_| | | \\__ \\                         \n"
" |____/ \\__,_|_|_|___/ _____                   \n"
"                 | |  / ____|                  \n"
"   __ _ _ __   __| | | |     _____      _____  \n"
"  / _` | '_ \\ / _` | | |    / _ \\ \\ /\\ / / __| \n"
" | (_| | | | | (_| | | |___| (_) \\ V  V /\\__ \\ \n"
"  \\__,_|_| |_|\\__,_|  \\_____\\___/ \\_/\\_/ |___/ \n"
    "                                               \n";

  
  std::cout << "\n" << asciiArt << "\n";  
  std::cout << "Can you guess the hidden isogram?\n";
  return;
}

// plays a single game to completion
void PlayGame()
{
  BCGame.Reset();
  BCGame.SetValidWordLength(GetValidWordLength());
  std::cout << "\nGuess the  " << BCGame.GetHiddenWordLength() << " letter hidden word!\n";
  int32 MaxTries = BCGame.GetMaxTries();
  
  while ( !BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries )
    {
      FText Guess = GetValidGuess();
      
      FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

      std::cout << "Bulls = " << BullCowCount.Bulls;
      std::cout << " Cows = " << BullCowCount.Cows << "\n\n";
    }
  
  PrintGameSummary();

  return;
}


FText GetValidGuess()
{
  FText Guess = "";
  EGuessStatus Status = EGuessStatus::Invalid_Status;
  do {
    std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ", enter your guess please: ";
    getline(std::cin, Guess); //  get a guess from the player
    Status = BCGame.CheckGuessValidity(Guess);
    
    switch (Status)
      {
      case EGuessStatus::Wrong_Length:
	std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
	break;
      case EGuessStatus::Not_Isogram:
	std::cout << "Please enter a word without repeating letters.\n\n";
	break;
      case EGuessStatus::Not_Lowercase:
	std::cout << "Please enter only lowercase characters.\n\n";      
	break;
      default:
	{ /* assume the guess is valid */  }
      }
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

int32 GetValidWordLength()
{
  int32 WordLength = 0;
  FText input = "";
  FRange range = BCGame.GetLengthRange();
  while ( (WordLength > range.Max ) || (WordLength <  range.Min) )
    {
      WordLength = 0;
      std::cout << "Please choose length of hidden isogram between ";
      std::cout << range.Min <<" and " << range.Max << std::endl;
      getline(std::cin, input);

      int32 exp = 1;
       for (auto letter : input)
	{
	  if ( letter > '9' || letter < '0') { WordLength = 0; break; }
	  WordLength += exp*(letter - '0');
	  exp = 10*exp;
	}

    }

  return WordLength;
}
