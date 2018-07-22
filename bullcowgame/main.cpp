#include <iostream> // to get access to cout, cin methods and << operator
//#include <string> // to get acces to >> operator

using namespace std; // using namespace - danger of namespace clash

void PrintIntro();
void PlayGame();
string GetGuess();
void PrintGuessBack(string Guess);
bool AskToPlayAgain();

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
  cout << "Welcome to Bulls and Cows, a fun word game." << endl;
  cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?" << endl;
  cout << endl;
  return;
}

void PlayGame()
{
  /* loop for the number of turns asking for guesses */
  constexpr int NUMBER_OF_TURNS = 5;
  string Guess = "";
  for(int count = 0; count < NUMBER_OF_TURNS; count++)
    {
      Guess = GetGuess();
      PrintGuessBack(Guess);
      cout << endl;
    }
  return;
}

/* get a guess from the player */
string GetGuess()
{
  string Guess = "";
  cout << "Enter your guess please: ";
  getline(cin, Guess);
  return Guess;
}

/* reapeat guess back to player */
void PrintGuessBack(string Guess)
{
  cout << "Here is your guess: " << Guess;
  cout << endl;
  return;
}

bool AskToPlayAgain()
{
  string Response = "";
  while(Response[0] != 'y' && Response[0] != 'Y' && Response[0] != 'n' && Response[0] != 'N')
    {
      cout << "Do you want to play again?- yes/no: ";
      getline(cin, Response);
    }
  
  return (Response[0] == 'y') || (Response[0] == 'Y');
}
