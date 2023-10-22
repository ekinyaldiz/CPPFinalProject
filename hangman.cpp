/* Project work C-course, block course WiSe 2023 
* Course participants: 
* Ekin Yaldiz
* Student ID: 2263663
*
* Project name: 
* Hangman Game
 *
 * Compiler call
 * g++ -std=c++11
 * 
 * 
 */

#include <iostream>
#include <fstream>
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
    srand(time(0));
    string word = words.at(rand()%words.size());

    for (int i=0; i < word.size(); i++)
    {
      answer.push_back(toupper(word[i]));
    }

    for (int i=0; i < answer.size(); i++)
    {
      guess.push_back('_');
    }
  }


  void play ()
  {
    //TODO Introduction to the game etc.
    //ADD: Another loop for multiple rouds of play-> Another function with a loop calling play multiple times!
    while (!(didLose()) && !(didWin()))
    {  
      char l = acceptLetter();
      bool correctLetter = false;
      //since it is already a new letter...
      for (int i=0; i < answer.size(); i++)
      {
        if (l == answer.at(i))
        {
          correctLetter = true;
          //TODO: Replace underscore with letter
          guess.at(i) = l;
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
        //cout << "before" << endl;
        showCurrentStatus(); 
        //cout << "after" << endl;
        cout << "\nCONGRATULATIONS!" << endl;
        cout << "You won!" << endl;
        break;
      }
    }
    return;
  }

  private:


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
    showCurrentStatus();
    char l;
    bool flag = true;
    cout << "Enter a letter" << endl;
    l = getchar();
    cin.clear();
    fflush(stdin);
    while (didRepeat(toupper(l)) || !isalpha(l) || cin.fail())
    {
      cin.clear();
      fflush(stdin);
      cout << "Entry invalid."<< endl;
      cout << "Enter only one character at a time" << endl;
      cout << "Enter a letter and do not repeat" << endl;
      l = getchar();
      cin.clear();
      fflush(stdin);
      cout << l << endl;
    }
    if (islower(l))
      l = toupper(l);
    used_letters.push_back(l);
    return l;
  }

  //returns true if the player has entered the same letter before, false if it is their first time guessing the letter
  bool didRepeat (char x)
  {
    for (auto i: used_letters)
    {
      if (i == x)
        return true;
    }
    return false;
  }

  //Already built-in function: isalpha()
  //Maybe combine with it the validation of a single character

  bool isLetter (char x)
  {
    //FIXME: Should it be just a char, or what if they enter something else??
    //TODO: After FIXME, check the ASCII value for valid characters in the game.
  }

  void showCurrentStatus ()
  {
        for (auto i: guess)
    {
      cout << i << ", ";
    }
  }

};

//Function reference: https://shorturl.at/azSU7
vector<std::string> readFileToVector(const std::string& filename)
{
    std::ifstream source;
    source.open(filename);
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(source, line))
    {
        lines.push_back(line);
    }
    return lines;
}


/* MAIN */
int main (int argc, char **argv) {

  string charactersFilename(argv[1]);
  vector<string> words = readFileToVector(charactersFilename);

  //TEST VECTOR
  //vector<string> words{"bounty", "ekin", "chris", "pablo"};

  Hangman hangman = Hangman(words);
  hangman.play();

  return 0;
}
