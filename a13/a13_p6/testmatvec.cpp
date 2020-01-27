#include <iostream>
#include <fstream>
#include "Vector.h"
#include "Matrix.h"

int main(int argc, char** argv) {
    double *firstComponents = new double[5]{1, 2, 3, 4, 5};
    double *secCompFirst = new double[4]{1, 3, 5, 7};
    double *secCompSecond = new double[4]{2, 4, 6, 8};
    double **secondComponents = new double*[2]{secCompFirst, secCompSecond};
    
    /* ----- Insert and Extract Vectors and Matrices from stdin ----- */
    Vector firstVectorInstanceStdin(NULL, 0);
    Matrix firstMatrixInstanceStdin(NULL, 0, 0);
    std::cout << "|------ Vector x Matrix Multiplication ------|" << std::endl
              << "Enter vector size and elements one after one: ";
    std::cin >> firstVectorInstanceStdin;
    std::cout << "\nVector inserted through stdin is:\n"
              << firstVectorInstanceStdin
              << std::endl;
    
    std::cout << "Enter matrix row number, column number and elements "
              << "one after one: ";
    std::cin >> firstMatrixInstanceStdin;
    std::cout << "\nMatrix inserted through stdin is:\n"
              << firstMatrixInstanceStdin
              << std::endl;
    
    std::cout << "Multiplication between inserted Vector and Matrix:\n"
              << firstVectorInstanceStdin * firstMatrixInstanceStdin
              << std::endl;

    Vector secondVectorInstanceStdin(NULL, 0);
    Matrix secondMatrixInstanceStdin(NULL, 0, 0);
    std::cout << "|------ Matrix x Vector Multiplication ------|" << std::endl
              << "Enter matrix row number, column number and elements "
              << "one after one: ";
    std::cin >> secondMatrixInstanceStdin;
    std::cout << "\nMatrix inserted through stdin is:\n"
              << secondMatrixInstanceStdin
              << std::endl;

    std::cout << "Enter vector size and elements one after one: ";
    std::cin >> secondVectorInstanceStdin;
    std::cout << "\nVector inserted through stdin is:\n"
              << secondVectorInstanceStdin
              << std::endl;    
    
    std::cout << "Multiplication between inserted Matrix and Vector:\n"
              << secondMatrixInstanceStdin * secondVectorInstanceStdin;
    /* -------------------------------------------------------------- */

    /* ---- Create Vector and Matrix instance using constructors ---- */
    // Vector Instance created using parametric constructor
    Vector firstInstance(firstComponents, 5);

    // Output user-defined data type Vector to standard output
    std::cout << "\nVector Instance:\n" << firstInstance << std::endl;

    // Matrix Instance created using parametric constructor
    Matrix secondInstance(secondComponents, 2, 4);

    // Output user-defined data type Matrix to standard output
    std::cout << "Matrix Instance:\n" << secondInstance;
    /* -------------------------------------------------------------- */

    /* --------- Insert and extract vectors from file stream -------- */
    // Open both in files
    std::ifstream in1("in1.txt"); // Vector input file
    std::ifstream in2("in2.txt"); // Matrix input file
    
    if (!in1.good()) { // Check if it didn't open successfully
        std::cerr << "Error opening input file 1!" << std::endl;
        exit(1);
    }

    if (!in2.good()) { // Check if it didn't open successfully
        std::cerr << "Error opening input file 1!" << std::endl;
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
        in1 >> firstInstance;
        in2 >> secondInstance;

        std::cout << "\nVector Instance read from file:\n"
                  << firstInstance
                  << std::endl;
        std::cout << "Matrix Instance read from file:\n"
                  << secondInstance
                  << std::endl;

        out << "Vector Instance read from file:\n"
            << firstInstance
            << std::endl;
        out << "Matrix Instance read from file:\n"
            << secondInstance
            << std::endl;

        out << "First Vector inserted through stdin is:\n"
            << firstVectorInstanceStdin
            << "\nFirst Matrix inserted through stdin is:\n"
            << firstMatrixInstanceStdin
            << "\nVector x Matrix Multiplication from stdin:\n"
            << firstVectorInstanceStdin * firstMatrixInstanceStdin
            << std::endl;

        out << "Second Vector inserted through stdin is:\n"
            << secondVectorInstanceStdin
            << "\nSecond Matrix inserted through stdin is:\n"
            << secondMatrixInstanceStdin
            << "\nMatrix x Vector Multiplication from stdin:\n"
            << secondMatrixInstanceStdin * secondVectorInstanceStdin;
    } else std::cout << "At least one of the files couldn't be opened!";

    // Close files
    in1.close();
    in2.close();
    out.close();
    /* -------------------------------------------------------------- */
    return 0;
}