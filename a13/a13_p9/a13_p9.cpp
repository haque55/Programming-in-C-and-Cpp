#include <iostream>

class Motor {
    private:
        std::string information;
    public:
        Motor() {
            // Throw exception when constructing Motor instance
            information = "This motor has problems";
            std::cerr << "Error in Motor : " << information << std::endl;
            throw information;
        }
};

class Car {
    private:
        Motor *motor;
    public:
        Car() {
            // Initialize motor when constructing Car instance
            motor = new Motor();
        }
};

class Garage {
    private:
        std::string info = "The car in this garage has problems with the motor";
        Car *car;
    public:
        Garage() {
            try {
                // Initialize car and check for thrown exceptions
                car = new Car();
            }
            catch (std::string Exception) {
                // Throw new string when catching exception from Motor
                throw info;
            }
        }
};

int main() {
    try {
        Garage obj;
    }
    catch (std::string mainException) {
        std::cerr << "Caught in main : " << mainException << std::endl;
    }
    return 0;
}