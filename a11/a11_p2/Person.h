#include <string>

class Person {
private:
	std::string name;
	int age;
	double height;
	std::string profession;
public:
	// Constructors
	// Parametric Constructor with all parameters
	Person(std::string Name, int Age, double Height, std::string Profession);
	// Empty Constructor with no parameters
	Person();
	// Copy Constructor
	Person(Person& person);
	
	// setter methods
	void setName(std::string newName);
	void setAge(int newAge);
	void setHeight(double newHeight);
	void setProfession(std::string newProfession);

	// getter methods
	std::string getName() const;
	int getAge() const;
	double getHeight() const;
	std::string getProfession() const;

	// service method
	void print() const;
};