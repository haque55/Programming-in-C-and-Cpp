// please refer to shapes.h for methods documentation

#include <iostream>

#define _USE_MATH_DEFINES // Solution to M_PI not declared in C++ Standard
#include <cmath>

#include "Shapes.h"

using namespace std;

/* ----------- Methods for Shape ----------- */
// Parametric constructor with all parameters
Shape::Shape(const string& n) : name(n) {}

// Default constructor
Shape::Shape() : name("Default Shape") {}

// Copy Constructor
Shape::Shape(const Shape& obj) {
	name = obj.name;
}

// Setter method for name data member
void Shape::setName(std::string Name) {
	name = Name;
}

// Getter method for name data member
std::string Shape::getName() const {
	return name;
}

// Method to print the name data member of the Shape
void Shape::printName() const {
	cout << name << endl;
}
/* ----------------------------------------- */

/* ------- Methods for CenteredShape ------- */
// Parametric constructor with all parameters
CenteredShape::CenteredShape(const string& n, double nx, double ny) : Shape(n) {
	x = nx;
	y = ny;
}

// Default constructor
CenteredShape::CenteredShape() : Shape("Default Centered Shape") {
	x = 0;
	y = 0;
}

// Copy constructor
CenteredShape::CenteredShape(const CenteredShape& obj) : Shape(obj.getName()) {
	x = obj.x;
	y = obj.y;
}

// Setter method for x data member
void CenteredShape::setX(double X) {
	x = X;
}

// Setter method for y data member
void CenteredShape::setY(double Y) {
	y = Y;
}

// Getter method for x data member
double CenteredShape::getX() const {
	return x;
}

// Getter method for y data member
double CenteredShape::getY() const {
	return y;
}

// Method to move the shape by changing both data members using setters
void CenteredShape::move(double X, double Y) {
	setX(X);
	setY(Y);
}
/* ----------------------------------------- */

/* ------- Methods for RegularPolygon ------ */
// Parametric constructor with all parameters
RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n, nx, ny) {
	EdgesNumber = nl;
}

// Default constructor
RegularPolygon::RegularPolygon()
				: CenteredShape("Default Regular Polygon", 0, 0) {
	EdgesNumber = 0;
}

// Copy constructor
RegularPolygon::RegularPolygon(const RegularPolygon& obj)
							  : CenteredShape(obj.getName(), obj.getX(),
											  obj.getY()) {
	EdgesNumber = obj.EdgesNumber;
}

// Setter method for EdgesNumber
void RegularPolygon::setEdgesNumber(int newEdgesNumber) {
	EdgesNumber = newEdgesNumber;
}

// Getter method for EdgesNumber
int RegularPolygon::getEdgesNumber() const {
	return EdgesNumber;
}
/* ----------------------------------------- */

/* ----------- Methods for Rectangle ------- */
// Parametric constructor with all parameters
Rectangle::Rectangle(const std::string& n, double nx, double ny, double NWidth,
		   double NHeight) : RegularPolygon(n, nx, ny, 4) { // 4-sided Polygon
	nwidth = NWidth;
	nheight = NHeight;
}

// Default constructor
Rectangle::Rectangle() : RegularPolygon("Default Rectangle", 0, 0, 4) {
	nwidth = 0;
	nheight = 0;
}

// Copy constructor
Rectangle::Rectangle(const Rectangle& obj) 
					: RegularPolygon(obj.getName(), obj.getX(), obj.getY(), 
									 obj.getEdgesNumber()) {
	nwidth = obj.nwidth;
	nheight = obj.nheight;
}

// Setter method for nwidth data member
void Rectangle::setNWidth(double NWidth) {
	nwidth = NWidth;
}

// Setter method for nheight data member
void Rectangle::setNHeight(double NHeight) {
	nheight = NHeight;
}

// Getter method for nwidth data member
double Rectangle::getNWidth() const {
	return nwidth;
}

// Getter method for nheight data member
double Rectangle::getNHeight() const {
	return nheight;
}

// Method to calculate perimeter of RegularPolygon Rectangle using getters
double Rectangle::perimeter() const {
	return (2 * (getNWidth() + getNHeight()));
}

// Method to calculate area of RegularPolygon Rectangle using getters
double Rectangle::area() const {
	return (getNWidth() * getNHeight());
}
/* ----------------------------------------- */

/* ----------- Methods for Square ---------- */
// Parametric constructor with all parameters
Square::Square(const std::string& n, double nx, double ny, double NSide)
		: Rectangle(n, nx, ny, NSide, NSide) {
	nside = NSide;
}

// Default constructor
Square::Square() : Rectangle("Default Square", 0, 0, 0, 0) {
	nside = 0;
}

// Copy constructor
Square::Square(const Square& obj) 
			  : Rectangle(obj.getName(), obj.getX(), obj.getY(), obj.getNSide(), 
			  			  obj.getNSide()) {
	nside = obj.nside;
}

// Setter method for nside data member
void Square::setNSide(double NSide) {
	nside = NSide;
}

// Getter method for nside data member
double Square::getNSide() const {
	return nside;
}

// Method to calculate perimeter of Rectangle Square using getters
double Square::perimeter() const {
	return (getNSide() * 4);
}

// Method to calculate area of Rectangle Square using setters
double Square::area() const {
	return (pow(getNSide(), 2));
}
/* ----------------------------------------- */

/* ----------- Methods for Circle ---------- */
// Parametric constructor with all parameters
Circle::Circle(const string& n, double nx, double ny, double r)
		: CenteredShape(n, nx, ny) {
	Radius = r;
}

// Default constructor
Circle::Circle() : CenteredShape("Default Circle", 0, 0) {
	Radius = 0;
}

// Setter method for Radius data member
void Circle::setRadius(double newRadius) {
	Radius = newRadius;
}

// Getter method for Radius data member
double Circle::getRadius() const {
	return Radius;
}

// Method to calculate CenteredShape Circle using getters
double Circle::perimeter() const {
	return (2 * M_PI * getRadius());
}

// Method to calculate CenteredShape Circle using getters
double Circle::area() const {
	return (M_PI * pow(getRadius(), 2));
}
/* ----------------------------------------- */