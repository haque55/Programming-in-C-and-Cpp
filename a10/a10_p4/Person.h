#include <string>

class Person {
	private:
		std::string name;
		int age;
		double height;
		std::string profession;
	public:
		// setter methods
		void setName(std::string newName);
		void setAge(int newAge);
		void setHeight(double newHeight);
		void setProfession(std::string newProfession);

		// getter methods
		std::string getName();
		int getAge();
		double getHeight();
		std::string getProfession();

		// service method
		void print();
};