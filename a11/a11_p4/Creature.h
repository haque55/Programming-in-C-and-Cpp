class Creature {
    protected:
		int distance;

    public:
        // Empty constructor
        Creature();

        // Destructor
        ~Creature();

        // Methods
        // Setter methods
        void setDist(int Distance);

        // Getter methods
        int getDist() const;

        // Service methods
        void run() const;
};

class Wizard : public Creature {
	private:
		int distFactor;

    public:
        // Empty constructor
        Wizard();

        // Destructor
        ~Wizard();

        // Methods
        // Setter methods
        void setDistFactor(int DistFactor);

        // Getter methods
        int getDistFactor() const;

        // Service methods
        void hover() const;
};

class Hobbit : public Creature {
    private:
        double caloriesPerDist;

    public:
        // Empty constructor
        Hobbit();

        // Destructor
        ~Hobbit();

        // Methods
        // Setter methods
        void setCaloriesPerDist(double CaloriesPerDist);

        // Getter methods
        double getCaloriesPerDist() const;

        // Service methods
        void caloriesUsed() const;
};

class Orc : public Creature {
    private:
        double basePower;

    public:
        // Empty constructor
        Orc();

        // Destructor
        ~Orc();

        // Methods
        // Setter methods
        void setBasePower(double BasePower);

        // Getter methods
        double getBasePower() const;

        // Service methods
        void punchingPower() const;  
};