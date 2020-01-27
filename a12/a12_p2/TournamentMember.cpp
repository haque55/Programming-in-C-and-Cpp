#include <iostream>
#include "TournamentMember.h"

std::string TournamentMember::location = "Default Location";

// Parametric constructor with all parameters
TournamentMember::TournamentMember(char const *firstN, char const *lastN,
                                   char const *dOB, std::string &Location,
                                   std::string Role, bool Active) {
    std::cout << "Parametric Constructor!\n";
    (*this).firstName = firstN;
    (*this).lastName = lastN;
    (*this).dateOfBirth = dOB;
    (*this).setLocation(Location);
    (*this).role = Role;
    (*this).active = Active;
}

// Default Constructor
TournamentMember::TournamentMember() {
    std::cout << "Default Constructor!\n";
    (*this).firstName = "Default";
    (*this).lastName = "Default";
    (*this).dateOfBirth = "0000-00-00";
    (*this).role = "Participant";
    (*this).active = true;
}

// Copy constructor
TournamentMember::TournamentMember(const TournamentMember& obj) {
    std::cout << "Copy Constructor!\n";
    (*this).firstName = obj.firstName;
    (*this).lastName = obj.lastName;
    (*this).dateOfBirth = obj.dateOfBirth;
    (*this).setLocation(obj.location);
    (*this).role = obj.role;
    (*this).active = obj.active;
}

// Destructor
TournamentMember::~TournamentMember() {
    std::cout << "Destructor!\n";
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