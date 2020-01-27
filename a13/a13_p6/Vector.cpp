#include <iostream>
#include <cmath>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

/*
    Vectors in input files are formatted:
        size
        elem_0
        elem_1
        ...
        elem_n
*/

Vector::Vector(double *Ptr, int Size) {
    (*this).size = Size;
    (*this).ptr = new double[(*this).size];
    for (int i = 0; i < (*this).size; i++)
        (*this).ptr[i] = Ptr[i];
}

Vector::Vector() {
    (*this).ptr = NULL;
    (*this).size = 0;
}

Vector::Vector(const Vector& obj) {
    (*this).size = obj.size;
    (*this).ptr = new double[(*this).size];
    for (int i = 0; i < obj.size; i++) {
        (*this).ptr[i] = obj.ptr[i];
    }
}

Vector::~Vector() {
    delete [] ptr;
}

void Vector::setPtr(double *Ptr, int PtrArrSize) {
    // Check if vector size matches before setting pointer
    if ((*this).size == PtrArrSize)
        (*this).ptr = Ptr;
}

void Vector::setSize(int Size) {
    delete [] ptr;
    (*this).size = Size;
    (*this).ptr = new double[(*this).size];
}

double* Vector::getPtr() const{
    return (*this).ptr;
}

int Vector::getSize() const {
    return (*this).size;
}

void Vector::printComponents() const {
    std::cout << "[ ";
    for (int i = 0; i < getSize(); i++) {
        if (i != (getSize() - 1)) {
            std::cout << getPtr()[i]
                      << " , ";
        } else std::cout << getPtr()[i];
    }
    std::cout << " ]" << endl;
}

double Vector::norm() const {
    double sum = 0;
    for (int i = 0; i < (*this).size; i++) {
        sum += pow((*this).ptr[i], 2);
    }
    return sqrt(sum);
}

Vector Vector::add(const Vector& secAddend) const {
    double *vecResult = new double[(*this).size];
    for (int i = 0; i < getSize(); i++)
        vecResult[i] = getPtr()[i] + secAddend.getPtr()[i];
    Vector additionVec(vecResult, (*this).size);
    return additionVec;
}

Vector Vector::subtract(const Vector& subtrahend) const {
    double *vecResult = new double[(*this).size];
    for (int i = 0; i < getSize(); i++)
        vecResult[i] = getPtr()[i] - subtrahend.getPtr()[i];
    Vector subtractionVec(vecResult, (*this).size);
    return subtractionVec;
}

double Vector::scalarProduct(const Vector& second) const {
    double scalProd = 0;
    for (int i = 0; i < getSize(); i++)
        scalProd += (getPtr()[i] * second.getPtr()[i]);
    
    return scalProd;
}

// Overloaded operator for Vector insertion
istream& operator>>(istream& in, Vector& obj) {
    int size;
    in >> size;
    obj.setSize(size);
    for (int i = 0; i < size; i++)
        in >> (obj.getPtr()[i]);
    return in;
}

// Overloaded operator for Vector extraction
ostream& operator<<(ostream& out, const Vector& obj) {
    out << "Elements: " << obj.getSize() << endl;
    for (int i = 0; i < obj.getSize(); i++)
        out << obj.getPtr()[i] << endl;
    return out;
}

// Overloaded multiplication operator to work with Vector x Matrix
Vector Vector::operator*(Matrix& matrix) {
    // Check if vector size is equal to matrix row size
    // Considering vector to always be a row vector of the form 1 x size
    if ((*this).size == matrix.getRows()) {
        double *resultVector = new double[matrix.getCols()];
        for (int i = 0; i < matrix.getCols(); i++){
            resultVector[i] = 0;
            for (int j = 0; j < matrix.getRows(); j++){
                resultVector[i] += (*this).ptr[j] * matrix.getPtr()[j][i];
            }
        }
        return Vector(resultVector, matrix.getCols());
    } else {
        std::cout << "Conditions for multiplication aren't satisfied!\n";
        return Vector();
    }
}