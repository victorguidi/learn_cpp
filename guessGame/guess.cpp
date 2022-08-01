#include <iostream>
#include <time.h>
using namespace std;

int main() {

  // In c++ we use cout for when we want to print something and we end the line
  // with endl
  cout << "Welcome to my Game!!" << endl;

  cout << "Choose the difficulty" << endl;
  cout << "Easy(E), Medium(M) and Hard(H)" << endl;

  // Creating levels of difficulty
  char difficulty;
  int trys = 0;

  cin >> difficulty;

  if (difficulty == 'E') {
    trys = 15;
  } else if (difficulty == 'M') {
    trys = 10;
  } else {
    trys = 5;
  }

  // Variables in c++ are static, so we must always pass the type, although we
  // do not have to give it a value:

  // The number that the player will have to find:
  // const int NUMBER = 50;

  // First it was a constant, but now we are randomly generating a new number
  // based on time
  srand(time(0));
  int number = rand() % 100;
  cout << number << endl;

  bool notGuessed = true;
  int guesses = 0;

  // adding a points system
  double score = 1000;

  cout << "The game has started, you have " << trys << " trys to guess" << endl;

  // adding a loop so the game won't finsih until the player guesses correclty
  // or the ammount of trys are over
  for (guesses = 1; guesses <= trys; guesses++) {
    int guess;

    cout << "This guess will be the number: " << guesses << endl;

    cout << "Guess a number: " << endl;

    // In order to read or receive an output, we can use cin:
    cin >> guess;

    // We can calculate the points already here becaue it is not related to the
    // fact if was correct or not
    double lost_points = abs(guess - number) / 2.0;
    score = score - lost_points;

    // Declare two boolean variables so it works as a condition for our
    // validation
    bool correct = guess == number;
    bool higher = guess > number;

    // There are three main logical operators, if, else if and else
    if (correct) {
      cout << "Your guess is correct!!" << endl;
      notGuessed = false;
      break;
    } else if (higher) {
      cout << "Your guess is bigger then the number" << endl;
    } else {
      cout << "Your guess is lower then the number" << endl;
    }
  }

  // adding 2 points of precision for our final score:
  cout.precision(2);
  cout << fixed;

  if (notGuessed) {
    cout << "You lost the game" << endl;
  } else {
    cout << "Congrats, you finished the game in: " << guesses - 1
         << " guesses!!" << endl;
    cout << "Your score was: " << score << endl;
  }
}
