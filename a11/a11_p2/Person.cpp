#include <iostream>
#include "Person.h"

using namespace std;

// Constructors
// Parametric Constructor with all parameters
Person::Person(string Name, int Age, double Height, string Profession) {
	name = Name;
	age = Age;
	height = Height;
	profession = Profession;
}
// Empty Constructor with no parameters
Person::Person() {
	name = "";
	age = 0;
	height = 0;
	profession = "";
}
// Copy Constructor
Person::Person(Person& person) {
	name = person.name;
	age = person.age;
	height = person.height;
	profession = person.profession;
}

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
string Person::getName() const {
	return name;
}

int Person::getAge() const {
	return age;
}

double Person::getHeight() const {
	return height;
}

string Person::getProfession() const {
	return profession;
}

// Method print outputs each data members' value through the getter methods
void Person::print() const {
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