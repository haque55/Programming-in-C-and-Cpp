#include <iostream>
#include "Person.h"

using namespace std;

// Setter methods for each data member of the class Person
void Person::setName(string newName) {
	name = newName;
}

void Person::setAge(int newAge) {
	age = newAge;
}

void Person::setHeight(double newHeight) {
	height = newHeight;
}

void Person::setProfession(string newProfession) {
	profession = newProfession;
}

// Getter methods for each data member of the class Person
string Person::getName() {
	return name;
}

int Person::getAge() {
	return age;
}

double Person::getHeight() {
	return height;
}

string Person::getProfession() {
	return profession;
}

// Method print outputs each data members' value through the getter methods
void Person::print() {
	cout << "Person: "
		 << getName()
		 << "\nAge: "
		 << getAge()
		 << " years old\nHeight: "
		 << getHeight()
		 << " meters\nProfession: "
		 << getProfession()
		 << endl;
}