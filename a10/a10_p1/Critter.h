#include <string> // defines standard C++ string class
 
/* First C++ class */
class Critter
{
private:  // data members are private
    int hunger;
    int boredom;
    double height;
	std::string name;
public: // business logic methods are public
    // setter methods
    void setName(std::string& newname) {
        name = newname;
    }
    void setHunger(int newhunger);
    void setBoredom(int newboredom);
    // getter method
    int getHunger();
    // service method
    void print();
};