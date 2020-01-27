#include <iostream>

using namespace std;

class Creature {
	public:
		Creature();
        ~Creature();
        void run() const;

	protected:
		int distance;
};

Creature::Creature() : distance(10) {}

Creature::~Creature() {
    cout << "Destroying Creature!\n";
}

void Creature::run() const { 
    cout << "running " << distance << " meters!\n";
}  

class Wizard : public Creature {
	public:
		Wizard();
        ~Wizard();
		void hover() const;

	private:
		int distFactor;
};

Wizard::Wizard() : distFactor(3) {}

Wizard::~Wizard() {
    cout << "Destroying Wizard!\n";
}

void Wizard::hover() const {
    cout << "hovering " << (distFactor * distance) << " meters!\n";
}

// Hobbit class as child of class Creature
class Hobbit : public Creature {
    public:
        Hobbit();
        ~Hobbit();
        void caloriesUsed() const;
    private:
        double caloriesPerDist;
};

Hobbit::Hobbit() : caloriesPerDist(11.4) {
    cout << "Constructed Hobbit using empty constructor!\n";
}

Hobbit::~Hobbit() {
    cout << "Destroying Hobbit!\n";
}

void Hobbit::caloriesUsed () const {
    cout << "Calories used: " << caloriesPerDist * distance << " calories!\n";
}

// Orc class as child of class Creature
class Orc : public Creature {
    public:
        Orc();
        ~Orc();
        void punchingPower() const;
    private:
        double basePower;
};

Orc::Orc() : basePower(100.0) {
    cout << "Constructed Orc using empty constructor!\n";
}

Orc::~Orc() {
    cout << "Destroying Orc!\n";
}

void Orc::punchingPower() const {
    cout << "Punching power: " << (basePower - ((basePower / 100) * distance))
         << " power!\n";
}

int main() { 
    cout << "Creating an Creature.\n";
    Creature c;
    c.run();

    cout << "\nCreating a Wizard.\n";
    Wizard w;
    w.run();
    w.hover();

    cout << "\nCreating a Hobbit.\n";
    Hobbit h;
    h.run();
    h.caloriesUsed();

    cout << "\nCreating an Orc.\n";
    Orc o;
    o.run();
    o.punchingPower();

    return 0;
}