#include <iostream>
#include "Creature.h"

using namespace std;

Creature::Creature() : distance(10) {}

Creature::~Creature() {
    cout << "Destroying Creature!\n";
}

void Creature::setDist(int Distance) {
    distance = Distance;
}

int Creature::getDist() const {
    return distance;
}

void Creature::run() const {
    cout << "running " << distance << " meters!\n";
}

Wizard::Wizard() : distFactor(3) {}

Wizard::~Wizard() {
    cout << "Destroying Wizard!\n";
}

void Wizard::setDistFactor(int DistFactor) {
    distFactor = DistFactor;
}

int Wizard::getDistFactor() const {
    return distFactor;
}

void Wizard::hover() const {
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

Hobbit::Hobbit() : caloriesPerDist(11.4) {
    cout << "Constructed Hobbit using empty constructor!\n";
}

Hobbit::~Hobbit() {
    cout << "Destroying Hobbit!\n";
}

void Hobbit::setCaloriesPerDist(double CaloriesPerDist) {
    caloriesPerDist = CaloriesPerDist;
}

double Hobbit::getCaloriesPerDist() const {
    return caloriesPerDist;
}

void Hobbit::caloriesUsed() const {
    cout << "Calories used: " << caloriesPerDist * distance << " calories!\n";
}

Orc::Orc() : basePower(100.0) {
    cout << "Constructed Orc using empty constructor!\n";
}

Orc::~Orc() {
    cout << "Destroying Orc!\n";
}

void Orc::setBasePower(double BasePower) {
    basePower = BasePower;
}

double Orc::getBasePower() const {
    return basePower;
}

void Orc::punchingPower() const {
    cout << "Punching power: " << (basePower - ((basePower / 100) * distance))
         << " power!\n";
}