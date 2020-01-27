/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>
#include <cmath>

/*
	In order to allow the copy constructor of Hexagon to work, I changed 
	some of the data members class access to protected to avoid 
	creating getters for each of those classes and changing every parametric
	constructor
*/

class Shape {			// base class
	protected:   			// private access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape&);		// copy constructor
		void printName() const ;  	// prints the name  
};

class CenteredShape : public Shape {  // inherits from Shape
	protected: 
		double x,y;  // the center of the shape
	public:
		// usual three constructors
		CenteredShape(const std::string&, double, double);
		CenteredShape();
		CenteredShape(const CenteredShape&);
		// moves the shape, i.e. it modifies it center
		void move(double, double);
};

// a regular polygon is a centered_shape with a number of edges
class RegularPolygon : public CenteredShape {
	protected:
		int EdgesNumber;
	public:
		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon();
		RegularPolygon(const RegularPolygon&);
};

class Hexagon : public RegularPolygon {
	private:
		int side;
		std::string color;
	public:
		// Parametric constructor with all parameters
		Hexagon(const std::string& name, double posX, double posY, int edgesNum,
				int Side, const std::string& Color);
		// Default constructor
		Hexagon();
		// Copy constructor
		Hexagon(const Hexagon& obj);
		// Destructor
		~Hexagon();

		// Setter methods
		void setSide(int Side);
		void setColor(std::string Color);

		// Getter methods
		int getSide() const;
		std::string getColor() const;

		// Method to calculate perimeter and return an integer
		int perimeter() const;
		// Method to calculate area and return a double
		double area() const;
};

// a Circle is a shape with a center and a radius
class Circle : public CenteredShape {
	private:
		double Radius;
	public:
		Circle(const std::string&, double, double, double);
		Circle();
		Circle(const Circle&);
};
    
#endif