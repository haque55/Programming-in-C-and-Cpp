#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int argc, char** argv) {
    int die;
    int count = 0;
    int random;
    // init random number generator
    srand(static_cast<unsigned int>(time(0)));
    const std::string colorsArray[4] = {"RED", "BLACK", "VIOLET", "BLUE"};
    while (count < 15) {
        random= rand();
        die = (random % 4);
        std::cout << "Roll " 
                  << count + 1 
                  << " : "
                  << die
                  << " : " 
                  << colorsArray[die] 
                  << std::endl;
        count++;
    }
    return 0;
}