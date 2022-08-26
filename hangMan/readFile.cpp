#include <fstream>
#include <string>
#include <time.h>
#include <vector>

std::vector<std::string> read_file() {
  std::ifstream file;
  file.open("words.txt");

  int n_words;
  file >> n_words;

  std::vector<std::string> words;
  for (int i = 0; i < n_words; i++) {
    std::string word;
    file >> word;
    words.push_back(word);
  }

  return words;
}

std::string randomize_words() {
  std::vector<std::string> words = read_file();

  srand(time(NULL));
  int random = rand() % words.size();

  return words[random];
}
