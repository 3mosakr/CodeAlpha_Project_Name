#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

#define MAX_NUM_OF_GUSS 100

int main() {

  // Use current time as seed for random generator
  srand(time(0));
  int secret_number = (rand() % MAX_NUM_OF_GUSS) + 1;
  int user_gussing = 0;
  int trials = 0;

  cout << "welcome to the Number Guessing game!\n";
  cout << "I have selected a number between 1 and 100. try to guess it.\n";

  do {
    cout << "Enter the your guess : ";
    cin >> user_gussing;
    trials++;

    if (user_gussing == secret_number) {
      cout << "Congratulation ! You guessed the number in " << trials
           << " trials.\n";
    } else if (user_gussing > secret_number) {
      cout << "Too high ! Try again.\n";
    } else {
      cout << "Too Low! Try again.\n";
    }
  } while (user_gussing != secret_number);

  return 0;
}
