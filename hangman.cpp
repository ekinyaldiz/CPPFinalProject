/*
TODO: Student info!
*/

#include <iostream>
//For randomly picking a word
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

//TODO: https://gist.github.com/chrishorton/8510732aa9a80a03c829b09f12e20d9c
// Artwork reference.

//TODO: Include array/text file to pick words from.
//FIXME: Broaden\: accept files as input for category picking.

class Hangman
{

  vector <char> answer;
  vector <char> guess;
  vector <char> used_letters;
  int lives = 10;

  //TODO: Write function
  public:
  Hangman(vector<string> &words)
  //The game, taking a category of words as input to choose randomly from.
  {
    for (int i=0; i < answer.size(); i++)
    {
      guess.push_back('_');
    }
    //TODO: Write the game
  }

  void play ()
  {

    bool newLetter = true;
    //TODO Introduction to the game etc.
    //ADD: Another loop for multiple rouds of play-> Another function with a loop calling play multiple times!
    //FIXME: Do I need the parantheses?
    while (!(didLose) && !(didWin))
    {
      char l = acceptLetter();
      for (auto i: used_letters)
      {
        if (l == i)
        {
          cout << "You have already entered this letter, please try a new one." << endl;
          newLetter = false;
          break;
        }
      }
      if (newLetter)
      {
        bool correctLetter = false;
        for (auto i: answer)
        {
          if (l == i)
          {
            correctLetter = true;
            //TODO: Replace underscore with letter
            //add l to used_letters
          }
        }
        if (!correctLetter)
        {
          lives--;
        }
      }
    }
    //TODO: Whichever is true: didLose or didWin, print corresponding messages.






    return;
  }

  private:

  //FIXME: Deal with how and which form to get the list of data later.
  // vector<char> pickword(vector <string> &words)
  // {
  //   //sth
  //   //IMPORTANT: return in uppercase for better visuals
  //   int size = words.size();
  //   string pick = words.at(rand() % size);
  //   return ();
  // }

  bool didWin ()
  {
    //TODO: declare global/class-wise "guess" and "answer"
    if (guess == answer)
      return true;
    else
      return false;
  }

  bool didLose()
  {
    if (lives == 0)
      return true;
    else
      return false;
  }


  char acceptLetter ()
  {
    char buffer;
    cout << "Enter a letter";
    cin >> buffer;
    //TODO: Multiple input checks, if wrong input given, retake the input: might need a loop
    //TODO: Convert letter to uppercase.
    return buffer;
  }
  //returns true if the player has entered the same letter before, false if it is their first time guessing the letter
  bool didRepeat (char x)
  {
    //TODO: Write function
  }

  bool isLetter (char x)
  {
    //FIXME: Should it be just a char, or what if they enter something else??
    //TODO: After FIXME, check the ASCII value for valid characters in the game.
  }

  //Takes a lowercase letter and converts it to uppercase, the 
  char upperCase (char l)
  {
    //TODO: Write function
  }

  void showCurrentStatus ()
  {
    //IF lives did not change..?
    //TODO: Print letters of guessed word and unknowns are stored as underscores.
  }









};


/* MAIN */
int main () {

  //TEST VECTOR
  vector<string> words {"ekin", "chris", "pablo", "bounty"};

  



  return 0;
}

