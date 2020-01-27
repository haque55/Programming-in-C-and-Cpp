#include <iostream>
#include "Shapes.h"

int main(int argc, char** argv) {
    Circle c("first circle", 3, 4, 7);
    RegularPolygon r("TRIANGLE", 1, 1, 3);
    
    r.printName();
    c.printName();
    
    Circle A("Test Instance Circle #1", 5, 10, 3);
    Rectangle B("Test Instance Rectangle #1", 2, 3, 4, 2);
    Square C("Test Instance Square #1", 3, 3, 5);

    std::cout << "Name: ";
    A.printName();
    std::cout << "Perimeter: "
              << A.perimeter()
              << "\nArea: "
              << A.area()
              << "\nName: ";
    B.printName();
    std::cout << "Perimeter: "
              << B.perimeter()
              << "\nArea: "
              << B.area()
              << "\nName: ";
    C.printName();
    std::cout << "Perimeter: "
              << C.perimeter()
              << "\nArea: "
              << C.area()
              << std::endl;
    
    return 0;
}