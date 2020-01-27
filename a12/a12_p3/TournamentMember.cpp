#include <iostream>
#include <string>
#include "TournamentMember.h"

/* ----- TournamentMember Class ----- */
std::string TournamentMember::location = "Default Location";

// Parametric constructor with all parameters
TournamentMember::TournamentMember(char const *firstN, char const *lastN,
                                   char const *dOB, std::string &Location,
                                   std::string Role, bool Active) {
    std::cout << "TournamentMember Parametric Constructor!\n";
    (*this).firstName = firstN;
    (*this).lastName = lastN;
    (*this).dateOfBirth = dOB;
    (*this).setLocation(Location);
    (*this).role = Role;
    (*this).active = Active;
}

// Default Constructor
TournamentMember::TournamentMember() {
    std::cout << "TournamentMember Default Constructor!\n";
    (*this).firstName = "Default";
    (*this).lastName = "Default";
    (*this).dateOfBirth = "0000-00-00";
    (*this).role = "Participant";
    (*this).active = true;
}

// Copy constructor
TournamentMember::TournamentMember(const TournamentMember& obj) {
    std::cout << "TournamentMember Copy Constructor!\n";
    (*this).firstName = obj.firstName;
    (*this).lastName = obj.lastName;
    (*this).dateOfBirth = obj.dateOfBirth;
    (*this).setLocation(obj.location);
    (*this).role = obj.role;
    (*this).active = obj.active;
}

// Destructor
TournamentMember::~TournamentMember() {
    std::cout << "TournamentMember Destructor!\n";
}

// Setter methods for each data member
inline void TournamentMember::setFirstName(char const *FirstName) {
    firstName = FirstName;
}

inline void TournamentMember::setLastName(char const *LastName) {
    lastName = LastName;
}

inline void TournamentMember::setDateOfBirth(char const *DateOfBirth) {
    dateOfBirth = DateOfBirth;
}

inline void TournamentMember::setLocation(std::string &Location) {
    location = Location;
}

inline void TournamentMember::setRole(std::string Role) {
    role = Role;
}

inline void TournamentMember::setActive(bool Active) {
    active = Active;
}

// Getter methods for each data members
inline char const* TournamentMember::getFirstName() const {
    return firstName;
}

inline char const* TournamentMember::getLastName() const {
    return lastName;
}

inline char const* TournamentMember::getDateOfBirth() const {
    return dateOfBirth;
}

inline std::string TournamentMember::getLocation() const {
    return location;
}

inline std::string TournamentMember::getRole() const {
    return role;
}

inline bool TournamentMember::getActive() const {
    return active;
}

// Method to output to stdout all data member of the instance formatted
void TournamentMember::printInformation() {
    std::cout << "First Name: "
              << getFirstName()
              << "\nLast Name: "
              << getLastName()
              << "\nDate of Birth: "
              << getDateOfBirth()
              << "\nLocation: "
              << getLocation()
              << "\nRole: "
              << getRole()
              << "\nActive: "
              << getActive()
              << std::endl;
}

// Method to change the static location data member
void TournamentMember::updateLocation(const std::string& updatedLocation) {
    std::cout << "Updating tournament location to "
              << updatedLocation
              << std::endl;
    location = updatedLocation;
}
/* ---------------------------------- */

/* ----- Player Class --------------- */
// Parametric constructor with all parameters
Player::Player(char const *firstN, char const *lastN, char const *dOB,
               std::string &Location, std::string Role, bool Active, int Number,
               std::string Position, int GoalsScored, std::string DomFoot)
               : TournamentMember(firstN, lastN, dOB, Location, "Player", 
                                  Active) {
    std::cout << "Player Parametric Constructor!\n";
    (*this).number = Number;
    (*this).position = Position;
    (*this).goalsScored = GoalsScored;
    (*this).dominantFoot = DomFoot;
}

// Default constructor
Player::Player() : TournamentMember() {
    std::cout << "Player Default Constructor!\n";
    (*this).setRole("Player");
    (*this).number = 0;
    (*this).position = "Default Position";
    (*this).goalsScored = 0;
    (*this).dominantFoot = "Neither";
}

// Copy constructor
Player::Player(const Player& obj) : TournamentMember(obj) {
    std::cout << "Player Copy Constructor!\n";
    (*this).number = obj.number;
    (*this).position = obj.position;
    (*this).goalsScored = obj.goalsScored;
    (*this).dominantFoot = obj.dominantFoot;
}

// Destructor
Player::~Player() {
    std::cout << "Player Destructor!\n";
}

// Method to output to stdout all data member of the instance Player formatted
void Player::printPlayerInformation() const {
    std::cout << "Number: "
              << getNumber()
              << "\nPosition: "
              << getPosition()
              << "\nGoals Scored: "
              << getGoalsScored()
              << "\nDominant Foot: "
              << getDominantFoot()
              << std::endl;
}

// Method to increment by 1 the data member goalsScored of Player instance
void Player::incrementGoalsScored() {
    int score = getGoalsScored();
    score++;
    (*this).goalsScored = score;
}
/* ---------------------------------- */