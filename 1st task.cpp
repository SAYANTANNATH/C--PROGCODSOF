#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator with the current time

    // Set a default secret number (you can change this value)
    int secretNumber = rand() % 100 + 1;

    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;

    do {
        cout << "Guess a number between 1 and 100: ";
        cin >> guess;

        if (guess < secretNumber) {
            cout << "Your guess is too low." << endl;
        } else if (guess > secretNumber) {
            cout << "Your guess is too high." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number " << secretNumber << "!" << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
