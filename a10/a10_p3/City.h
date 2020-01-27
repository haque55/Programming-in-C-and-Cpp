#include <string>

class City {
	private:
		int population;
		double area;
		std::string name;
		std::string mayor;
	public:
		// setter methods
		void setName(std::string newName);
		void setArea(double newArea);
		void setPopulation(int newPopulation);
		void setMayor(std::string newMayor);

		// getter methods
		std::string getName();
		double getArea();
		int getPopulation();
		std::string getMayor();

		// service method
		void print();
};