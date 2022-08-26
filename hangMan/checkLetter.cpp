#include <string>

bool checkLetter(std::string word, char letter) {

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
