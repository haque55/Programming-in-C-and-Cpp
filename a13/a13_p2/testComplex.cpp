#include <iostream>
#include <fstream>
#include "Complex.h"

/*
     Programs reads complex numbers of one of the forms:
     >>a+bi    >>-a+bi   >>a-bi    >>-a-bi
*/

int main(int argc, char **argv) {
     Complex firstNumber, secondNumber, result;

     // Open both in files
     std::ifstream in1("in1.txt");
     std::ifstream in2("in2.txt");
     
     if (!in1.good()) { // Check if it didn't open successfully
          std::cerr << "Error opening input file 1!" << std::endl;
          exit(1);
     }

     if (!in2.good()) { // Check if it didn't opne successfully
          std::cerr << "Error opening input file 2!" << std::endl;
          exit(1);
     }

     // Open the out file with truncate flag
     std::ofstream out("output.txt", std::ios::trunc);
     if (!out.good()) { // Check if it didn't open successfully
          std::cerr << "Error opening output file!" << std::endl;
          exit(2);
     }

     // Check if files are open
     if (in1.is_open() && in2.is_open() && out.is_open()) {
          in1 >> firstNumber;
          in2 >> secondNumber;
          result = firstNumber + secondNumber;
          std::cout << "Sum of complex numbers: " << result << std::endl;
          out << "Sum of complex numbers: " << result << std::endl;
          result = firstNumber - secondNumber;
          std::cout << "Difference of complex numbers: " << result << std::endl;
          out << "Difference of complex numbers: " << result << std::endl;
          result = firstNumber * secondNumber;
          std::cout << "Product of complex numbers: " << result << std::endl;
          out << "Product of complex numbers: " << result;
     } else std::cout << "At least one of the files couldn't be opened!";

     // Close files
     in1.close();
     in2.close();
     out.close();

     return 0;
}