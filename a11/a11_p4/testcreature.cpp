#include <iostream>
#include "Creature.h"
using namespace std;

int main() {
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    cout << "\nCreating a Hobbit.\n";
    Hobbit h;
    h.run();
    h.caloriesUsed();

    cout << "\nCreating an Orc.\n";
    Orc o;
    o.run();
    o.punchingPower();

    return 0;
}