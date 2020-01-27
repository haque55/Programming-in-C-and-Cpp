#ifndef __VECTOR_H
#define __VECTOR_H
class Vector {
    private:
        double *ptr;
        int size;
    public:
        Vector(double *Ptr, int Size);
        Vector();
        Vector(const Vector&);
        ~Vector();

        void setPtr(double *Ptr);
        void setSize(int Size);

        double* getPtr() const;
        int getSize() const;

        void printComponents() const;
        double norm() const;
        Vector add(const Vector& secAddend) const;
        Vector subtract(const Vector& subtrahend) const;
        double scalarProduct(const Vector& second) const;
};
#endif