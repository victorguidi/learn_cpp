
#include <map>
#include <string>

bool not_guessed(std::string word, std::map<char, bool> hide) {
  for (char l : word) {
    if (!hide[l]) {
      return true;
    }
  }
  return false;
}
