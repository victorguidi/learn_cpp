#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool checkLetter(string word, char letter) {

  // Oldschool loop
  // for (int i = 0; i < word.size(); i++) {
  //   if (letter == word[i]) {
  //     return true;
  //   }
  // }

  // More modern loop
  for (char l : word) {
    if (letter == l) {
      return true;
    }
  }

  return false;
}

bool not_guessed(string word, map<char, bool> hide) {
  for (char l : word) {
    if (!hide[l]) {
      return true;
    }
  }
  return false;
}

bool not_hanged(vector<char> wrong_guesses) { return wrong_guesses.size() < 5; }

vector<string> read_file() {
  ifstream file;
  file.open("words.txt");

  int n_words;
  file >> n_words;

  vector<string> words;
  for (int i = 0; i < n_words; i++) {
    string word;
    file >> word;
    words.push_back(word);
  }

  return words;
}

string randomize_words() {
  vector<string> words = read_file();

  srand(time(NULL));
  int random = rand() % words.size();

  return words[random];
}

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
