#include <iostream>
#include "Creature.h"
using namespace std;

int main() {
    string line;
    getline(cin, line); // Get first line of input

    // Infinite loop until input is "quit"
    while (line != "quit") {
        // Check if line is "wizard", "hobbit", "orc"
        if (line == "wizard") {
            cout << "\nCreating a Wizard.\n";
            Wizard *w = new Wizard;
            (*w).run();
            (*w).hover();
            delete w;
        } else if (line == "hobbit") {
            cout << "\nCreating a Hobbit.\n";
            Hobbit *h = new Hobbit;
            (*h).run();
            (*h).caloriesUsed();
            delete h;
        } else if (line == "orc") {
            cout << "\nCreating an Orc.\n";
            Orc *o = new Orc;
            (*o).run();
            (*o).punchingPower();
            delete o;
        }

        getline(cin, line); // Get next input
    }

    return 0;
}