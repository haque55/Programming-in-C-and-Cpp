#include <iostream>
#include "Box.h"
 
using namespace std;

// Constructor Box with 2 parameters
Box::Box(double Height, double Width, double Depth) {
    height = Height;
    width = Width;
    depth = Depth;
}

// Constructor Box with no parameters sets value to 0 to data members
Box::Box() {
    height = 0;
    width = 0;
    depth = 0;
}

// Copy constructor
Box::Box(Box& box) {
    // Copy data members
    height = box.height;
    width = box.width;
    depth = box.depth;
}

// Destructor Box
Box::~Box() {
    // Empty destructor
}

// Setter methods for each data member of Box class 
void Box::setH(double Height) {
    height = Height;
}

void Box::setW(double Width) {
    width = Width;
}

void Box::setD(double Depth) {
    depth = Depth;
}

// Getter methods for each data member of Box class
double Box::getH() const {
    return height;
}

double Box::getW() const {
    return width;
}

double Box::getD() const {
    return depth;
}