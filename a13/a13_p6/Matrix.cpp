#include <iostream>
#include <cmath>
#include "Vector.h"
#include "Matrix.h"

/*
    Matrices in input files are formatted:
        rows
        columns
        elem_0_0
        elem_0_1
        ...
        elem_0_n
        elem_1_n
        ...
        elem_m_n
*/

Matrix::Matrix(double **Ptr, int Rows, int Cols) {
    (*this).rows = Rows;
    (*this).cols = Cols;
    (*this).ptr = new double*[(*this).rows];

    for (int i = 0; i < (*this).rows; i++)
        ptr[i] = new double[(*this).cols];

    for (int i = 0; i < (*this).rows; i++)
        for (int j = 0; j < (*this).cols; j++)
            (*this).ptr[i][j] = Ptr[i][j];
}

Matrix::Matrix() {
    (*this).rows = 0;
    (*this).cols = 0;
    ptr = NULL;
}

Matrix::Matrix(const Matrix& obj) {
    (*this).rows = obj.rows;
    (*this).cols = obj.cols;
    (*this).ptr = new double*[(*this).rows];

    for (int i = 0; i < (*this).rows; i++)
        ptr[i] = new double[(*this).cols];

    for (int i = 0; i < (*this).rows; i++)
        for (int j = 0; j < (*this).cols; j++)
            (*this).ptr[i][j] = obj.ptr[i][j];
}

Matrix::~Matrix() {
    for (int i = 0; i < (*this).rows; i++)
        delete [] ptr[i];
    delete [] ptr;
}

void Matrix::setPtr(double **Ptr, int PtrRows, int PtrCols) {
    // Check if matrix size matches before setting pointer
    if ((*this).rows == PtrRows && (*this).cols == PtrCols)
        (*this).ptr = Ptr;
}

void Matrix::setRows(int Rows) {
    // Delete entire matrix
    for (int i = 0; i < (*this).rows; i++)
        delete [] ptr[i];
    delete [] ptr;
    (*this).rows = Rows;
    // Allocate memory for new row sizes
    (*this).ptr = new double*[(*this).rows];
    for (int i = 0; i < (*this).rows; i++)
        (*this).ptr[i] = NULL;
}

void Matrix::setCols(int Cols) {
    // Delete columns set before
    if ((*this).ptr == NULL) {
        for (int i = 0; i < (*this).rows; i++) {
            delete [] (*this).getPtr()[i];
        } 
    }
    (*this).cols = Cols;
    // Allocate memory for new column sizes
    for (int i = 0; i < (*this).rows; i++)
        ptr[i] = new double[(*this).cols];
}

double** Matrix::getPtr() const {
    return (*this).ptr;
}

int Matrix::getRows() const {
    return (*this).rows;
}

int Matrix::getCols() const {
    return (*this).cols;
}

std::istream& operator>>(std::istream& in, Matrix& obj) {
    int rows, cols;
    in >> rows >> cols;
    
    obj.setRows(rows);
    obj.setCols(cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) 
            in >> obj.ptr[i][j];
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& obj) {
    out << "Rows: " << obj.rows << std::endl
        << "Columns: " << obj.cols << std::endl;
    for(int i = 0; i < obj.rows; i++)
        for(int j = 0; j < obj.cols; j++)
            out << obj.ptr[i][j] << std::endl;
    return out;
}


// Overloaded multiplication operator to work with Matrix x Vector
Vector Matrix::operator*(Vector& vector) {
    // Check if column number of matrix is equal to vector size
    // Considering vector to always be a column vector of the form size x 1
    if ((*this).cols == vector.getSize()) {
        double *resultVector = new double[(*this).getRows()];
        for (int i = 0; i < (*this).getRows(); i++) {
            resultVector[i] = 0;
            for (int j = 0; j < (*this).getCols(); j++) {
                resultVector[i] += (*this).getPtr()[i][j] * vector.getPtr()[j];
            }
        }
        return Vector(resultVector, (*this).getRows());
    } else {
        std::cout << "Conditions for multiplication aren't satisfied!\n";
        return Vector();
    }
   return Vector();
}