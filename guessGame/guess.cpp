#include <iostream>
using namespace std;

int main() {

  // In c++ we use cout for when we want to print something and we end the line
  // with endl
  cout << "Welcome to my Game!!" << endl;

  // Variables in c++ are static, so we must always pass the type, although we
  // do not have to give it a valeu:
  const int NUMBER = 50;
  bool notGuessed = true;
  int guesses = 0;

  // adding a loop so the game won't finsih until the player guesses correclty
  while (notGuessed) {
    guesses++;
    int guess;

    cout << "This guess will be the number: " << guesses << endl;

    cout << "Guess a number: " << endl;

    // In order to read or receive an output, we can use cin:
    cin >> guess;

    // Declare two boolean variables so it works as a condition for our
    // validation
    bool correct = guess == NUMBER;
    bool higher = guess > NUMBER;

    // There are three main logical operators, if, else if and else
    if (correct) {
      cout << "Your guess is correct!!" << endl;
      notGuessed = false;
    } else if (higher) {
      cout << "Your guess is bigger then the number" << endl;
    } else {
      cout << "Your guess is lower then the number" << endl;
    }
  }
  cout << "Congrats, you finished the game in: " << guesses << " guesses!!"
       << endl;
}
