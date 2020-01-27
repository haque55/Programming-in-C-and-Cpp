#include <iostream>
#include "Shapes.h"

int main(int argc, char** argv) {
    Hexagon firstInstance("Hexagon #1", 4, 4, 6, 9, "White");
    Hexagon secondInstance("Hexagon #2", 2, 5, 6, 15, "Blue");
    Hexagon thirdInstance(secondInstance);

    std::cout << "Name: ";
    firstInstance.printName();
    std::cout << "Perimeter: "
              << firstInstance.perimeter()
              << "\nArea: "
              << firstInstance.area()
              << std::endl;

    std::cout << "Name: ";
    secondInstance.printName();
    std::cout << "Perimeter: "
              << secondInstance.perimeter()
              << "\nArea: "
              << secondInstance.area()
              << std::endl;

    std::cout << "Name: ";
    thirdInstance.printName();
    std::cout << "Perimeter: "
              << thirdInstance.perimeter()
              << "\nArea: "
              << thirdInstance.area()
              << std::endl;

    return 0;
}