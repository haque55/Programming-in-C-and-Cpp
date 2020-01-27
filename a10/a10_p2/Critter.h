#include <string> // defines standard C++ string class
 
/* First C++ class */
class Critter
{
private:  // data members are private
    int hunger;
    int boredom;
    double height;
    double length;
    std::string name;
    std::string hairColor;
 
public:
    // business logic methods are public
    // setter methods
    void setName(std::string& newname);

    void setLength(double newlength);
    void setHairColor(std::string& newhairColor);
	
    void setHunger(int newhunger);
    void setBoredom(int newboredom);
    // getter method
    int getHunger();
    double getLength();
    std::string getHairColor();
    // service method
    void print();
};