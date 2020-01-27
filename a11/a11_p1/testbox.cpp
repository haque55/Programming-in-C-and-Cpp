#include <iostream>
#include "Box.h"

using namespace std;

int main(int argc, char **argv) {
    int n;
    double height, width, depth, volume;

    cin >> n;

    // Dynamically allocate memory for 2 * n boxes
    Box *arrBox = new Box[2*n];

    // Input each data member of each instance using respective setters
    for (int i = 0; i < n; i++) {
        cout << "Set height of box " << i<< " : ";
        cin >> height;
        arrBox[i].setH(height);
        cout << "Set width of box " << i << " : ";
        cin >> width;
        arrBox[i].setW(width);
        cout << "Set depth of box " << i << " : ";
        cin >> depth;
        arrBox[i].setD(depth);
    }

    // Initialize data members for 2nd group of instances using copy constructor
    for (int i = n; i < (2 * n); i++) {
        arrBox[i] = arrBox[i-n];
    }

    // Print out the volume of each instance
    for (int i = 0; i < (2 * n); i++) {
        volume = arrBox[i].getH() * arrBox[i].getW() * arrBox[i].getD();
        cout << "Volume of box " << i << " is: " << volume << endl; 
    }

    delete [] arrBox;
    
    return 0;
}