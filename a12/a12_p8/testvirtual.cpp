#include <iostream>
using namespace std;
#include "Area.h"
#include "Circle.h"
#include "Ring.h"
#include "Rectangle.h"
#include "Square.h"

/*
	   DIAGRAM OF CLASS RELATIONS

			/////////////
			/	Area	/
			/////////////
			 ||		  ||
			 ||		  ||
	//////////////	///////////////
	/   Circle   /	/  Rectangle  /
	//////////////	///////////////
		  ||			  ||
		  ||			  ||
	//////////////	///////////////
	/    Ring    /	/    Square   /
	//////////////	///////////////
*/

/*
	Explanations for numbered points

	(1) - Create an array of num_obj Area type pointers
	(2) - Integer index used to go through the list in the while loop at (7)
	(3) - Double sum_area which holds the sum of all the area of the instances
		  which will be created in the following statements
	(4) - Following lines up until (5) declare and initialize a creation of a
		  new instance while also outputting a message onto stdout about the 
		  creation of that instance
	(5) - Following lines assign the addresses of the instances created before
		  (5) to the elements of the array of Area type pointers
	(7) - While loop traversing the array of Area type pointers
	(8) - Assign the return value of calcArea method being called on the current
		  instance which is referred to by the address found on the current
		  index of the array of Area type pointers, to double area
		  Increment index by 1 and add value of area to sum_area
	(9) - Value of sum_area which is the sum of all the areas of the instances
		  created before is outputted into stdout using cout

*/
const int num_obj = 7;
int main() {
	Area *list[num_obj];						// (1)
	int index = 0;								// (2)
	double sum_area = 0.0;						// (3)
	cout << "Creating Ring: ";
	Ring blue_ring("BLUE", 5, 2);				// (4)
	cout << "Creating Circle: ";
	Circle yellow_circle("YELLOW", 7);
	cout << "Creating Rectangle: ";
	Rectangle green_rectangle("GREEN",5,6);
	cout << "Creating Circle: ";
	Circle red_circle("RED", 8);
	cout << "Creating Rectangle: ";
	Rectangle black_rectangle("BLACK", 10, 20);
	cout << "Creating Ring: ";
	Ring violet_ring("VIOLET", 100, 5);
	cout << "Creating Square: ";
	Square crimson_square("CRIMSON", 10);
	list[0] = &blue_ring;						// (5)
	list[1] = &yellow_circle;
	list[2] = &green_rectangle;
	list[3] = &red_circle;
	list[4] = &black_rectangle;
	list[5] = &violet_ring;
	list[6] = &crimson_square;
	while (index < num_obj) {					// (7)
		(list[index])->getColor();				
		double area = list[index++]->calcArea();// (8)
		sum_area += area;
	}
	cout << "\nThe total area is "
			<< sum_area << " units " << endl;	// (9)
	
	double sum_perimeter = 0.0;
	index = 0;
	while (index < num_obj) {
		(list[index])->getColor();
		double perimeter = list[index++]->calcPerimeter();
		sum_perimeter += perimeter;
	}
	cout << "\nThe total perimeter is "
			<< sum_perimeter << " units " << endl;
	return 0;
}