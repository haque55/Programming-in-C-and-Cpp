#include <iostream>

using namespace std;

// Overloaded function swapping that returns nothing

// Swapping takes 2 integers and swaps their values
void swapping(int &firstInt, int &secondInt);
// Swapping takes 2 floats and swaps their values
void swapping(float &firstFloat, float &secondFloat);
// Swapping takes 2 const char pointers and swaps them
void swapping(const char *&firstString, const char *&secondString);

int main(void) {
    int a = 7, b = 15;
    float x = 3.5, y = 9.2;
    const char *str1 = "One";
    const char *str2 = "Two";

    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;

    swapping(a, b);
    swapping(x, y);
    swapping(str1, str2);

    cout << "a=" << a << ", b=" << b << endl;
    cout << "x=" << x << ", y=" << y << endl;
    cout << "str1=" << str1 << ", str2=" << str2 << endl;

    return 0;
}

void swapping(int &firstInt, int &secondInt) {
    int temp = firstInt;
    firstInt = secondInt;
    secondInt = temp;
}

void swapping(float &firstFloat, float &secondFloat) {
    float temp = firstFloat;
    firstFloat = secondFloat;
    secondFloat = temp;
}

void swapping(const char *&firstString, const char *&secondString) {
    const char *temp = firstString;
    firstString = secondString;
    secondString = temp;
}