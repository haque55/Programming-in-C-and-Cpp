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