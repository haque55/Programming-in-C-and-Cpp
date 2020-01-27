#include <iostream>
#include "fraction.h"

using namespace std;

int main(int argc, char** argv) {
    bool comparisonResult;
	Fraction firstInstance, secondInstance, sum, difference;

    cout << "Enter 2 fractions:\n";
    // Enter data members of both instances using overloaded ">>"
    cin >> firstInstance;
    cin >> secondInstance;

    comparisonResult = firstInstance.operator>(secondInstance);

    if (comparisonResult == 1) {
        cout << "Greater fraction is: "
             << firstInstance
             << endl;
    } else {
        cout << "Greater fraction is: "
              << secondInstance
              << endl;
    }
    
    sum = firstInstance + secondInstance;
    difference = firstInstance - secondInstance;

    cout << "Sum of fractions is: "
         << sum
         << "\nDifference of fractions is: "
         << difference
         << endl;
    
    return 0;
}