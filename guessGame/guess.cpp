#include <iostream>
using namespace std;

int main() {

  // In c++ we use cout for when we want to print something and we end the line
  // with endl
  cout << "Welcome to my Game!!" << endl;

  // Variables in c++ are static, so we must always pass the type, although we
  // do not have to give it a valeu:
  int number = 50;

  int guess;

  cout << "Guess a number: " << endl;

  // In order to read or receive an output, we can use cin:
  cin >> guess;

  // There are three main logical operators, if, else if and else
  if (guess == number) {
    cout << "Your guess is correct!!" << endl;
  } else if (guess > number) {
    cout << "Your guess is bigger then the number" << endl;
  } else {
    cout << "Your guess is lower then the number" << endl;
  }
}
