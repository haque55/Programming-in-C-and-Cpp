#include <iostream>

// Function returns a float value, takes a float
// It returns the absolute value of the input float
float abs(float number);

int main(int argc, char **argv) {
    float x;

    std::cin >> x; // Input float
    std::cout << abs(x); // Output the absolute value of float
    
    return 0;
}

float abs(float number) {
    if (number >= 0)
        return number;
    else return (-number); // Return positive value
}