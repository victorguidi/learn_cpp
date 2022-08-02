#include <iostream>
#include <string>
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

int main() {
  string word = "guess";
  cout << word << endl;

  // boolean variables that will help us to create the condition for the loop
  bool not_guessed = true;
  bool not_hanged = true;

  while (not_guessed && not_hanged) {
    char guess;
    cin >> guess;

    if (checkLetter(word, guess)) {
      cout << "This letter exists in the word" << endl;
    } else {
      cout << "This letter does not exists in the word" << endl;
    }
  }
}
