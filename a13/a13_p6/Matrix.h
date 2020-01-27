#include "Vector.h"
#ifndef __MATRIX_H
#define __MATRIX_H

// Class Vector declared here to overcome cyclic dependency  due to the fact 
// that a cyclic dependency among header files is a design flaw.
class Vector;

class Matrix {
    private:
        double **ptr;
        int rows, cols;
    public:
        Matrix(double **Ptr, int Rows, int Cols);
        Matrix();
        Matrix(const Matrix& obj);
        ~Matrix();

        void setPtr(double **Ptr, int PtrRows, int PtrCols);
        void setRows(int Rows);
        void setCols(int Cols);

        double** getPtr() const;
        int getRows() const;
        int getCols() const;

        // Overloaded operators for Matrix insertion and extraction
        friend std::istream& operator>>(std::istream& in, Matrix& obj);
        friend std::ostream& operator<<(std::ostream& out, const Matrix& obj);

        // Overloaded multiplication operator to work with Matrix x Vector
        Vector operator*(Vector& vector);
};
#endif