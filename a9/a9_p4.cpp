#include <iostream>

// Overloaded function mycount that receives 2 integers as arguments and returns
// the difference between the second and first integer
int mycount(int a, int b);

// Overloaded function mycount that receives one char and one string as 
// as arguments and returns the occurence of the char in the string
int mycount(char ch, std::string s);

int main(int argc, char **argv) {
    int firstNum = 49, secondNum = 93, result;

    // Call overloaded function mycount with int parameters
    result = mycount(firstNum, secondNum); // Should return 44
    std::cout << result << std::endl;

    // Call overloaded function mycount with char and string parameters
    result = mycount('l', "hello world!"); /// Should return 3
    std::cout << result << std::endl;

    return 0;
}

int mycount(int a, int b) {
    return b - a;
}

int mycount(char ch, std::string s) {
    int count = 0;
    // Traverse the string and check each character
    for (int i = 0; i < (int) s.length(); i++) {
        if (s[i] == ch)
            count++;
    }
    return count;
}