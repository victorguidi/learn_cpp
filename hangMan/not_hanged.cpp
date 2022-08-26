#include <vector>

bool not_hanged(std::vector<char> wrong_guesses) {
  return wrong_guesses.size() < 5;
}
