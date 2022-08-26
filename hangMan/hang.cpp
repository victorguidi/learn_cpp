#include "checkLetter.hpp"
#include "not_guessed.hpp"
#include "not_hanged.hpp"
#include "readFile.hpp"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  string word = randomize_words();

  // Using maps is c++ is just like using a dict
  map<char, bool> hide;
  // In order to create dynamic arrays in c++ we can use vectors:
  vector<char> wrong_guesses;
  // boolean variables that will help us to create the condition for the loop

  while (not_guessed(word, hide) && not_hanged(wrong_guesses)) {

    cout << "You already guessed this words: ";

    for (char l : wrong_guesses) {
      cout << l << " ";
    }
    cout << endl;

    for (char l : word) {
      if (hide[l]) {
        cout << l;
      } else {
        cout << "_ ";
      }
    }
    cout << endl;

    char guess;
    cin >> guess;

    hide[guess] = true;

    if (checkLetter(word, guess)) {
      cout << "This letter exists in the word" << endl;
    } else {
      cout << "This letter does not exists in the word" << endl;
      wrong_guesses.push_back(guess);
    }

    cout << endl;
  }

  if (not_hanged(wrong_guesses)) {
    cout << "Congrats! You won the game, and the word was: " << word << endl;
  } else {
    cout << "You lost the game! The word was: " << word << endl;
  }
}
