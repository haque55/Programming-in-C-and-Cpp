#include <iostream>
#include "City.h"

using namespace std;

// Setter methods for each data member of the class City
void City::setName(string newName) {
	name = newName;
}

void City::setArea(double newArea) {
	area = newArea;
}

void City::setPopulation(int newPopulation) {
	population = newPopulation;
}

void City::setMayor(string newMayor) {
	mayor = newMayor;
}

// Getter methods for each data member of the class City
string City::getName() {
	return name;
}

double City::getArea() {
	return area;
}

int City::getPopulation() {
	return population;
}

string City::getMayor() {
	return mayor;
}

// Method print outputs each data members's value through the getter methods
void City::print() {
	cout << "City: "
		 << getName()
		 << "\nPopulation: "
		 << getPopulation()
		 << " inhabitants\nArea: "
		 << getArea()
		 << " square kilometers\nMayor: "
		 << getMayor()
		 << endl;
}