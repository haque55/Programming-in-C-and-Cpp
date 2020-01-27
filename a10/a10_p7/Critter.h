#include <string> // defines standard C++ string class

class Critter {
    private: // data members are private
        std::string name;
        double hunger; // hunger is stored as a double type
        int boredom;
        double height;
        double thirst;

        // Methods to convert from int to double and from double to int

        // Method to convert data member double to int using casting as int and
        // multiplication by 10
        int convertUncover();
        // Method to convert inputted int to double using casting as double and
        // division by 10
        double convertHide(int Hunger);

    public:
        // Constructors
        // Construct Critter object with all parameters supplied
        Critter(std::string Name, int Hunger, int Bored,
                    double Height, double Thirst);
        // Construct Critter object with 4 parameters supplied
        // In case height is ommited, set height to default value 10
        Critter(std::string Name, int Hunger, int Bored, double Height = 10.0);
        // Construct Critter object with name parameter supplied
        Critter(std::string Name);
        // Construct Critter with no parameters supplied
        Critter();

        // setter methods
        void setName(std::string &newName);
        void setHunger(int newHunger);
        void setBoredom(int newBoredom);
        void setHeight(double newHeight);
        void setThirst(double newThirst);

        // getter methods
        std::string getName();
        int getHunger();
        int getBoredom();
        double getHeight();
        double getThirst();

        // service method
        void print();
};