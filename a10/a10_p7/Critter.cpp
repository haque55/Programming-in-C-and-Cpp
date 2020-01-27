#include <iostream>
#include "Critter.h"
 
using namespace std;

/*
	Remark about interpretation of the problem
		For the existing constructors, the
		thirst level should be set to the same level as the hunger level.
	This can be interpreted either way as just set it to the value provided
	that is the integer that the constructor is being called with, 
	or the internal value of hunger level that is double
	Because of this I chose to go with the internal hunger value
*/

// Construct Critter object with all parameters supplied
Critter::Critter(string Name, int Hunger, int Bored, 
					double Height, double Thirst) {
	cout << "Constructor supplied with all parameters\n";
	name = Name;
	hunger = convertHide(Hunger);
	boredom = Bored;
	height = Height;
	thirst = Thirst;
}

// Construct Critter object with 4 parameters supplied
// In case height is ommited, set height to default value 10
Critter::Critter(string Name, int Hunger, int Bored, double Height) {
    cout << "Constructor supplied with 4 parameters\n";
	name = Name;
	hunger = convertHide(Hunger);
	boredom = Bored;
	height = Height;
	thirst = convertHide(Hunger);
}

// Construct Critter object with name parameter supplied
Critter::Critter(string Name) : name(Name) {
    cout << "Constructor supplied with only 1 parameter\n";
	hunger = 0;
	boredom = 0;
	height = 5;
	thirst = 0.0;
}

// Construct Critter with no parameters supplied
Critter::Critter() {
    cout << "Constructor supplied with no parameters\n";
    name = "default_critter";
    hunger = 0;
    boredom = 0;
    height = 5;
	thirst = 0.0;
}

// Setter methods for each data member of Critter class
void Critter::setName(std::string& newName) {
    name = newName;
}
 
void Critter::setHunger(int newHunger) {
    hunger = convertHide(newHunger);
}

void Critter::setBoredom(int newBoredom) {
    boredom = newBoredom;
}

void Critter::setHeight(double newHeight) {
    height = newHeight;
}

void Critter::setThirst(double newThirst) {
	thirst = newThirst;
}

// Getter methods for each data member of Critter class
string Critter::getName() {
    return name;
}
 
int Critter::getHunger() {
    return convertUncover();
}

int Critter::getBoredom() {
    return boredom;
}

double Critter::getHeight() {
    return height;
}

double Critter::getThirst() {
	return thirst;
}

// Methods used to hide information

int Critter::convertUncover() {
	// Return the int casted value of multiplication of hunger and 10
	// To go from 1.0 as value of data member to 10, 0.5 to 5, and so on...
    return ((int) (hunger * 10));
}

double Critter::convertHide(int Hunger) {
	// Return the double casted value of divison of hunger and 10
	// To go from 10 as input to 1.0, 5 to 0.5, and so on...
    return (((double) Hunger) / 10);
}

// Method print outputs each data members' value through the getter methods
void Critter::print() {
	cout << "Name: "
		 << getName()
		 << "\nHunger: "
		 << getHunger()
		 << "\nBoredom: "
		 << getBoredom()
		 << "\nHeight: "
		 << getHeight()
		 << "\nThirst: "
		 << getThirst()
		 << endl;
}