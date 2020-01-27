#include <string>

class Complex {
    private:
        int real;
        int imaginary;

    public:
        // Constructors
        // Construct Critter object with all parameters supplied
        Complex(int real, int complex);
        // Construct Complex with no parameters supplied
        Complex();
        // Copy constructor
        Complex(Complex& num);

        // Destructor
        ~Complex();

        // setter methods
        void setReal(int newReal);
        void setImaginary(int newImaginary);

        // getter methods
        int getReal();
        int getImaginary();

        // service method
        Complex add(Complex& num); 
        Complex sub(Complex& num); 
        Complex mul(Complex& num);
        Complex conjugate();
        void print();
};