#include <iostream>
#include <cmath>

int arraySize = 7;

// Overloaded function myfirst that returns int, double or char depending on
// arguments given to it when called

// Takes a pointer to an int array and returns the first positive and even value
// of the array
// If no such value is found, it returns -1
int myfirst(int *intArr);

// Takes a pointer to a double array and returns the first negative value of 
// the array that has no fractional part
// If no such value is found, it returns -1.1
double myfirst(double *doubleArr);

// Takes a pointer to a char array and returns the first consonant character
// of the array
// If no such character is found, it returns '0'
char myfirst(char *charArr);

int main(int argc, char **argv) {
    // Initialize arrays inside code
    int numbers[] = {-4, 3, 1, 0, 4, -2, 8};
    double doubles[] = {-2.5, 1.2, 0, 3.3, -2.0, 28.2, -7.0};
    char chars[] = {'A', 'I', 'o', 'b', 'y', 's', 'H'};

    // Function should return 4
    std::cout << "Calling myfirst() with int array\n"
              << myfirst(numbers)
              << std::endl;
    
    // Function should return -2
    std::cout << "Calling myfirst() with double array\n"
              << myfirst(doubles)
              << std::endl;

    // Function should return 'b'
    std::cout << "Calling myfirst() with char array\n"
              << myfirst(chars)
              << std::endl;

    return 0;
}

int myfirst(int *intArr) {
    // Traverse the array of ints
    for (int i = 0; i < arraySize; i++) {
        // Check if array integer is positive and even
        if ((intArr[i] > 0) && (intArr[i] % 2 == 0))
            return intArr[i];
    }
    return -1;
}

double myfirst(double *doubleArr) {
    // Traverse the array of doubles
    for (int i = 0; i < arraySize; i++) {
        // Check if array double is negative and has no fractional part
        // by using the floor function
        if ((doubleArr[i] < 0) && (doubleArr[i] == floor(doubleArr[i])))
            return doubleArr[i];
    }
    return -1.1;
}

char myfirst(char charArr[]) {
    // Traverse the array of chars
    for (int i = 0; i < arraySize; i++) {
        char ch = tolower(charArr[i]);
        // Check if character is a letter of alphabet first
        if (isalpha(ch)) {
            // Check if it is not a vowel
            if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
                return charArr[i];
        }
    }
    return '0';
}