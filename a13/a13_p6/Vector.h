#ifndef __VECTOR_H
#define __VECTOR_H
#include "Matrix.h"
class Vector {
    private:
        double *ptr;
        int size;
    public:
        Vector(double *Ptr, int Size);
        Vector();
        Vector(const Vector& obj);
        ~Vector();

        void setPtr(double *Ptr, int PtrArrSize);
        void setSize(int Size);

        double* getPtr() const;
        int getSize() const;

        void printComponents() const;
        double norm() const;
        Vector add(const Vector& secAddend) const;
        Vector subtract(const Vector& subtrahend) const;
        double scalarProduct(const Vector& second) const;
       
        // Overloaded operators for Vector insertion and extraction
        friend std::istream& operator>>(std::istream& in, Vector& obj);
        friend std::ostream& operator<<(std::ostream& out, const Vector& obj);

        // Overloaded multiplication operator to work with Vector x Matrix
        Vector operator*(Matrix& matrix);
};
#endif