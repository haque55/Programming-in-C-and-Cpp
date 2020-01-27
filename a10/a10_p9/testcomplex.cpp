#include <iostream>
#include <cstdlib>
#include "Complex.h"

using namespace std;

int main(int argc, char **argv) {
    int real, imaginary;
    Complex firstNumber, secondNumber, thirdNumber;

    cout << "Enter first number's parts: \n"
         << "Real: ";
    cin >> real;
    cout << "Imaginary: ";
    cin >> imaginary;

    firstNumber.setReal(real);
    firstNumber.setImaginary(imaginary);

    cout << "Enter second number's parts: \n"
         << "Real: ";
    cin >> real;
    cout << "Imaginary: ";
    cin >> imaginary;

    secondNumber.setReal(real);
    secondNumber.setImaginary(imaginary);

    cout << "Conjugate of first number: ";
    thirdNumber = firstNumber.conjugate();
    thirdNumber.print();

    cout << "Sum of the two complex numbers: ";
    thirdNumber = firstNumber.add(secondNumber);
    thirdNumber.print();

    cout << "Difference between second and first number: ";
    thirdNumber = secondNumber.sub(firstNumber);
    thirdNumber.print();

    cout << "Multiplication of the two complex numbers: ";
    thirdNumber = firstNumber.mul(secondNumber);
    thirdNumber.print();

    return 0;
}