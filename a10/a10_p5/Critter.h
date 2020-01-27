#include <string> // defines standard C++ string class
 
class Critter {
    private:  // data members are private
        std::string name;
        int hunger;
        int boredom;
        double height;
    
    public:
        // Constructors
        // Construct Critter object with all parameters supplied
        // In case height is ommited, set height to default value 10
        Critter(std::string Name, int Hunger, int Bored, double Height = 10.0);
        // Construct Critter object with name parameter supplied
        Critter(std::string Name);
        // Construct Critter with no parameters supplied
        Critter();

        // setter methods
        void setName(std::string& newName);
        void setHunger(int newHunger);
        void setBoredom(int newBoredom);
        void setHeight(double newHeight);

        // getter methods
        std::string getName();
        int getHunger();
        int getBoredom();
        double getHeight();

        // service method
        void print();
};