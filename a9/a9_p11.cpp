#include <iostream>
#include <ctime>

// Function returns a boolean value and takes a string as an argument
// It returns true if the string is palindrome
// Else it returns false
bool isPalindrome(std::string s);

int main(int argc, char **argv) {
    std::string word;
    std::string exit = "exit";
    std::cout << "Check if a word is palindromic!\nEnter your word: ";
    std::cin >> word;

    // Check if the word matches "exit"
    while (word != exit) {
        bool isPalindromic = isPalindrome(word);
        // Output different messages according to the result of isPalindrome()
        if (isPalindromic) {
            std::cout << "The word "
                      << word
                      << " is a palindrome!\n";
        } else {
            std::cout << "The word "
                      << word
                      << " is not a palindrome!\n";
        }
        std::cout << "Enter your word: ";
        std::cin >> word;
    }
    return 0;
}

bool isPalindrome(std::string s) {
    int count = 0; // Count the number of matching characters from both ends
    // Iterate until the middle of the string
    for (int i = 0; i < (int) (s.length() / 2); i++) {
        // Check if characters with same difference from both sides of the word
        // are the same
        if (s[i] == s[s.length() - 1 - i])
            count++;
        else continue;
    }
    // Check if the number of matching characters is equal to half the length
    // of the string we are checking
    if (count == (int) (s.length() / 2))
        return true;
    else return false;
}