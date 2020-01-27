#include <iostream>
#include "Vector.h"

int main(int argc, char** argv) {
    double *firstComponents = new double[5]{1, 2, 3, 4, 5};
    double *thirdComponents = new double[5]{10, 6, 4, 2, 3};

    // Instance created using default constructor
    Vector firstInstance;
    std::cout << "Components of first Vector (default constructed): ";
    firstInstance.printComponents();
    firstInstance.setPtr(firstComponents);
    firstInstance.setSize(5);
    std::cout << "Components of first Vector (components set using setter): ";
    firstInstance.printComponents();

    // Instance created using copy constructor
    Vector secondInstance(firstInstance);
    std::cout << "Component of second Vector (copy constructed): ";
    secondInstance.printComponents();

    // Instance created using parametric constructor
    Vector thirdInstance(thirdComponents, 5);
    std::cout << "Component of third Vector (parametric constructed): ";
    thirdInstance.printComponents();

    std::cout << "Norm of first Vector: "
              << firstInstance.norm()
              << std::endl;
    
    std::cout << "Scalar Product of first and third Vector: "
              << firstInstance.scalarProduct(thirdInstance)
              << std::endl;

    std::cout << "Sum of first and third Vector: ";
    (firstInstance.add(thirdInstance)).printComponents();

    std::cout << "Difference of first and third Vector: ";
    (firstInstance.subtract(thirdInstance)).printComponents();

    return 0;
}