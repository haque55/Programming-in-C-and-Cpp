#include <string>

class TournamentMember {
    private:
        const char *firstName;
        const char *lastName;
        const char *dateOfBirth;
        static std::string location;
        std::string role;
        bool active;
    public:
        // Constructors
        TournamentMember(char const *firstN, char const *lastN, char const *dOB,
                         std::string &Location, std::string Role, bool Active);
        TournamentMember();
        TournamentMember(const TournamentMember& obj);

        // Destructor
        ~TournamentMember();

        // Setter methods
        inline void setFirstName(const char *FirstName);
        inline void setLastName(const char *LastName);
        inline void setDateOfBirth(const char *DateOfBirth);
        inline static void setLocation(std::string &Location);
        inline void setRole(std::string Role);
        inline void setActive(bool Active);

        // Getter methods
        inline const char* getFirstName() const;
        inline const char* getLastName() const;
        inline const char* getDateOfBirth() const;
        inline std::string getLocation() const;
        inline std::string getRole() const;
        inline bool getActive() const;

        // Methods
        // Method to print all data members of an instance to stdout
        void printInformation();
        // Method to change the static location data member
        static void updateLocation(const std::string& updatedLocation);
};

class Player : public TournamentMember {
    private:
        int number;
        std::string position;
        int goalsScored;
        std::string dominantFoot;
    public:
        // Constructors
        Player(char const *firstN, char const *lastN, char const *dOB,
               std::string &Location, std::string Role, bool Active, int Number,
               std::string Position, int GoalsScored, std::string DomFoot);
        Player();
        Player(const Player& obj);

        // Destructor
        ~Player();

        // Setter methods
        void setNumber(int Number) {number = Number;}
        void setPosition(std::string Position) {position = Position;}
        void setDominantFoot(std::string DomFoot) {dominantFoot=DomFoot;}

        // Getter methods
        inline int getNumber() const {return number;}
        inline std::string getPosition() const {return position;}
        inline int getGoalsScored() const {return goalsScored;}
        inline std::string getDominantFoot() const {return dominantFoot;}

        // Methods
        void printPlayerInformation() const;
        void incrementGoalsScored();
};