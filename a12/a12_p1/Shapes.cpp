#include <iostream>
#include "Shapes.h"

using namespace std; 

Shape::Shape(const string& n) : name(n) {
}

void Shape::printName() const {
	cout << name << endl;
}

CenteredShape::CenteredShape(const string& n, double nx, double ny): Shape(n) {
	x = nx;
	y = ny;
}

RegularPolygon::RegularPolygon(const string& n, double nx, double ny, int nl) :
	CenteredShape(n,nx,ny) 
{
	EdgesNumber = nl;
}

Hexagon::Hexagon(const string& name, double posX, double posY, 
				   int edgesNum, int Side, const std::string& Color)
				: RegularPolygon(name, posX, posY, edgesNum) {
	side = Side;
	color = Color;
	cout << "Parametric Constructed: "
		 << color
		 << " Hexagon with side length "
		 << side
		 << endl;
}

Hexagon::Hexagon() : RegularPolygon("Default Hexagon", 0.0, 0.0, 6) {
	side = 0;
	color = "White";
	cout << "Default Constructed: White Hexagon with side length 0"
		 << endl;
}

Hexagon::Hexagon(const Hexagon& obj) : RegularPolygon(obj.name, obj.x, obj.y,
													  obj.EdgesNumber) {
	side = obj.side;
	color = obj.color;
	cout << "Copy Constructed: "
		 << color
		 << " Hexagon with side length "
		 << side
		 << endl;
}

Hexagon::~Hexagon() {
	cout << "Destructor called!\n";
}

void Hexagon::setSide(int Side) {
	side = Side;
}

void Hexagon::setColor(std::string Color) {
	color = Color;
}

int Hexagon::getSide() const {
	return side;
}

std::string Hexagon::getColor() const {
	return color;
}

int Hexagon::perimeter() const {
	return (getSide() * 6);
}

double Hexagon::area() const {
	return (1.5 * sqrt(3) * pow(getSide(), 2));
}

Circle::Circle(const string& n, double nx, double ny, double r) :
  CenteredShape(n,nx,ny) 
{
	Radius = r;
}