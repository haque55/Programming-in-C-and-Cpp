#include <iostream>
#include <ctime>

using namespace std;

int n = 17; // Number of words in the array

int main(int argc, char **argv) {
    int randomNumber, tries;
    string guess, answer;
    string exit = "exit";
    string words[n] = {"computer","television","keyboard","laptop","mouse"};
    cout << "Welcome to the word guess game!\nEnter 12 words:\n";
    // Input the remaining words for the word guess game
    for (int i = 5; i < n; i++)
        getline(cin, words[i]);

    do {
        // init random number generator
        srand(static_cast<unsigned int>(time(0)));
        randomNumber = (rand() % n); // Get number from 0-16
        tries = 0; // Set number of tries to 0 each new game
        string temp = words[randomNumber]; // Save word to temporary string

        // Traverse the whole temp string and change each vowel to a 
        for(int i = 0; i < (int) temp.length(); i ++) {
            char ch = temp[i];
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                temp[i] = '_';
            }
        }        
        
        cout << "Word to guess: " << temp << endl;

        while (1) { // Infinite loop to guess the word
            cout << "Your guess of the word: ";
            cin >> guess;
            tries++; // Increment number of tries

            if (guess == exit) { // Check if word guess is "exit"
                return 0;
            } else if (guess == words[randomNumber]) {
                // Check if word guess is the randomly chosen word
                cout << "Number of tries: " << tries << endl;
                cout << "Would you like to play again? YES/NO\n";
                cin >> answer;
                if (answer == "YES")
                    break; // Break out of the guess word infinite loop
                else if (answer == "NO")
                    return 0; // Stop execution
            } else {
                continue; // Guess again
            }
        }
    } while (1); // Infinite loop to play the game again
    
    return 0;
}