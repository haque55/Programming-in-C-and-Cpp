#include <iostream>
#include "fraction.h"

using namespace std;

int main(int argc, char** argv) {
	Fraction firstInstance, secondInstance;

    cout << "Enter 2 fractions to perform multiplication and division with:\n";
    // Enter data members of both instances using overloaded ">>"
    cin >> firstInstance;
    cin >> secondInstance;

    // Output multiplication and division between both fracs using 
    // overloaded "*", "/"
    cout << "Product: " << firstInstance * secondInstance << endl;
    cout << "Quotient: " << firstInstance / secondInstance << endl;

    return 0;
}