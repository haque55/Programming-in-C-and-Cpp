#include <iostream>
#include <ctime>

int main(int argc, char **argv) {
    int guess;
    int tries = 0;
    int randomNumber;
    std::string name;

    std::cout << "Enter your name: ";
    std::cin >> name;

    std::cout << "Welcome to the Guess-A-Number game!\n";

    // init random number generator
    srand(static_cast<unsigned int>(time(0)));
    randomNumber = (rand() % 100) + 1; // Get number from 1-100

    while (1) { // Infinite loop to guess
        std::cout << "Guess number: ";
        std::cin >> guess;

        tries++;

        // Output different messages depending on the guess
        if (guess < randomNumber)
            std::cout << "Guessed number is too low!\n";
        else if (guess > randomNumber)
            std::cout << "Guessed number is too high!\n";
        else {
            std::cout << "Good Job "
                      << name
                      << "! You guessed right the number "
                      << randomNumber
                      << " after "
                      << tries
                      << " tries!"
                      << std::endl;
            break;
        }
    }
    return 0;
}