#include <iostream>
#include <cstdlib>
#include "Critter.h"

using namespace std;

int main(int argc, char **argv) {
    // Creating Critter Objects and then outputting data members into stdout
    // First instance using constructor with no parameters supplied
    Critter A;
    A.setHunger(2); // Set hunger to 2 using setHunger method
    A.print();

    // Second instance using constructor with name parameter supplied
    Critter B("Barney");
    B.setHunger(2); // Set hunger to 2 using setHunger method
    B.print();

    // Third instance using constructor with 3 parameters omitting height
    Critter C("Cupcake", 2, 10);
    C.print();

    // Fourth instance using constructor with 4 parameters
    Critter D("Jade", 2, 50, 150.0);
    D.print();
    
    return 0;
}