#include <iostream>
#include <cstdlib>
#include "City.h"

using namespace std;

int main(int argc, char** argv) {
	City Bremen, Paris, London;

	// Set value for each data member of the three instances
	Bremen.setName("Bremen");
	Bremen.setPopulation(569352);
	Bremen.setMayor("Andreas Bovenschulte");
	Bremen.setArea(326.73);

	Paris.setName("Paris");
	Paris.setPopulation(2140526);
	Paris.setMayor("Anne Hidalgo");
	Paris.setArea(105.4);

	London.setName("London");
	London.setPopulation(8908081);
	London.setMayor("Sadiq Khan");
	London.setArea(1572);

	// Output the data members of each instance through the public print method
	Bremen.print();
	Paris.print();
	London.print();

	return 0;
}