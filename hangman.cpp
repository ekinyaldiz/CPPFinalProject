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
  public:

  vector <char> answer;
  vector <char> guess;
  vector <char> used_letters;
  int lives = 10;

  Hangman(vector<string> &words)
  //The game, taking a category of words as input to choose randomly from.
  {
    //FIXME: Turn it into random picking after test
    //For testing only
    string testt = words[0];

    for (int i=0; i<words[0].size(); i++)
    {
      answer.push_back(testt[i]);
    }

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
    while (!(didLose()) && !(didWin()))
    {
      char l = acceptLetter();
      //FIXME: Get rif of the if, already checked in aceptLetter whether the letter is repeated or not
      bool correctLetter = false;
      //since it is already a new letter...
      for (auto i: answer)
      {
        if (l == i)
        {
          correctLetter = true;
          //TODO: Replace underscore with letter
          char to_replace = answer.at(i);
          guess.at(i) = to_replace;
        }
      }

      if (!correctLetter)
      {
        lives--;
        //ASCII Art
        //The rest of the status info is given later
        cout << "\nYou have " << lives << " lives left." << endl;
      }
      if (didLose())
      {
        string str(answer.begin(), answer.end());
        cout << "You lost!" << endl;
        cout << "The word was: " << str << "." << endl;
        break;
      }
      if (didWin())
      {
        cout << "CONGRATULATIONS!" << endl;
        cout << "You won!" << endl;
        break;
      }
    }
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

  //TEST VERSION: Only give uppercase letters as input
  char acceptLetter ()
  {
    char l;
    cout << "Enter a letter" << endl;
    cin >> l;
    used_letters.push_back(l);
    //TODO: Multiple input checks, if wrong input given, retake the input: might need a loop
    //TODO: Convert letter to uppercase.
    return l;
  }

  //returns true if the player has entered the same letter before, false if it is their first time guessing the letter
  bool didRepeat (char x)
  {
    for (auto i: used_letters)
    {
      if (i  == x)
        return true;
    }
    return false;
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
  vector<string> words{"ekin", "chris", "pablo", "bounty"};

  Hangman hangman = Hangman(words);

  //TEST BEGIN
  cout << "Answer is: " << endl;
  for (auto i: hangman.answer)
  {
    cout << i << endl;
  }

  cout << "/n/nGuess is: " << endl;
  for (auto i: hangman.guess)
  {
    cout << i << endl;
  }
  //TEST END
  
  hangman.play();

  return 0;
}

