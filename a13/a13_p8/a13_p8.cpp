#include <iostream>

class OwnException : public std::exception {
    private:
        std::string Exception;
    public:
        // Parametric constructor
        OwnException(std::string except) {
            (*this).Exception = except;
        }
        // Overriden what() method
        virtual const char* what() const noexcept {
            return "OwnException\n";
        }
};

void exceptionThrower(int input) {
    // Different cases depending on input throw different exceptions
    switch(input) {
        case 1:
            throw 'a';
            break;
        case 2:
            throw 2;
            break;
        case 3:
            throw true;
            break;
        default:
            throw OwnException("Default case exception");
            break;
    }
}

int main() {
    // Loop to go through all possible cases of the switch case in 
    for (int i = 1; i < 5; i++) {
        try {
            exceptionThrower(i);
        }
        catch (char error) {
            std::cerr << "Caught in main: " << error << std::endl;
        }
        catch (int error) {
            std::cerr << "Caught in main: " << error << std::endl;
        }
        catch (bool error) {
            std::cerr << "Caught in main: " << error << std::endl;
        }
        catch (OwnException& error) {
            std::cerr << "Caught in main: " << error.what() << std::endl;
        }
    }
    return 0;
}