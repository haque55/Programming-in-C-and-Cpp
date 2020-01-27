/* 
	Classic shape examples: an inheritance tree in a geometric context
*/
#ifndef __SHAPES_H
#define __SHAPES_H
#include <string>

class Shape {			// base class
	private:   				// private access modifier: could also be protected
		std::string name;   // every shape will have a name
	public:
		Shape(const std::string&);  // builds a shape with a name
		Shape();					// empty shape
		Shape(const Shape& obj);		// copy constructor

		void setName(std::string Name); // setter method for name

		std::string getName() const;	// getter method for name
		void printName() const;  		// prints the name  
};

class CenteredShape : public Shape {  // inherits from Shape
	private: 
		double x, y;  // the center of the shape
	public:
		// Parametric constructor with all parameters
		CenteredShape(const std::string&, double, double);
		CenteredShape(); // Default constructor
		CenteredShape(const CenteredShape& obj); // Copy constructor

		void setX(double X);		// Setter method for x
		void setY(double Y);		// Setter method for y

		double getX() const;		// Getter method for x
		double getY() const;		// Getter method for y

		// moves the shape, i.e. it modifies it center
		void move(double, double);	
};

// a regular polygon is a centered_shape with a number of edges
class RegularPolygon : public CenteredShape {
	private: 
		int EdgesNumber; // number of edges of the polygon
	public:
		// Parametric constructor with all parameters
		RegularPolygon(const std::string&, double, double, int);
		RegularPolygon(); // Default constructor
		RegularPolygon(const RegularPolygon& obj); // Copy constructor

		// Setter method for EdgesNumber
		void setEdgesNumber(int newEdgesNumber);
		
		int getEdgesNumber() const; // Getter method for EdgesNumber
};

class Rectangle : public RegularPolygon {
	private:
		double nwidth;
		double nheight;
	public:
		// Parametric constructor with all parameters
		Rectangle(const std::string& n, double nx, double ny, double NWidth,
				  double NHeight);
		Rectangle(); // Default constructor
		Rectangle(const Rectangle& obj); // Copy constructor

		void setNWidth(double NWidth); // Setter method for nwidth
		void setNHeight(double NHeight); // Setter method for nheight

		double getNWidth() const; // Getter method for nwidth
		double getNHeight() const; // Getter method for nheight

		double perimeter() const; // Calculate perimeter
		double area() const; // Calculate area
};

class Square : public Rectangle {
	private:
		double nside;
	public:
		// Parametric constructor with all parameters
		Square(const std::string& n, double nx, double ny, double NSide);
		Square(); // Default constructor
		Square(const Square& obj); // Copy constructor
		
		void setNSide(double NSide); // Setter method for nside

		double getNSide() const; // Getter method for nside

		double perimeter() const; // Calculate perimeter
		double area() const; // Calculate area
};

// a Circle is a shape with a center and a radius
class Circle : public CenteredShape {
	private:
		double Radius;
	public:
		// Parametric constructor with all 
		Circle(const std::string&, double, double, double);
		Circle(); // Default constructor
		Circle(const Circle&); // Copy constructor

		void setRadius(double newRadius); // Setter method for Radius
		
		double getRadius() const; // Getter method for Radius

		double perimeter() const; // Calculate perimeter
		double area() const; // Calculate area
};
#endif