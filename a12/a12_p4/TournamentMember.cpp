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

/* ----- Referee Class -------------- */
// Parametric constructor with all parameters
Referee::Referee(char const *firstN, char const *lastN, char const *dOB,
                 std::string &Location, std::string Role, bool Active)
                 : TournamentMember(firstN, lastN, dOB, Location, "Referee", 
                                    Active) {
    std::cout << "Referee Parametric Constructor!\n";
    // Initialize each data member to 0 and NULL
    (*this).yellowCardCount = 0;
    (*this).redCardCount = 0;
    for (int i = 0; i < 40   ; i++)
        yellowCardList[i] = NULL;
    for (int i = 0; i < 40; i++)
        redCardList[i] = NULL;
}

// Default constructor
Referee::Referee() : TournamentMember() {
    std::cout << "Referee Default Constructor!\n";
    (*this).setRole("Referee");
    // Initialize each data member to 0 and NULL
    (*this).yellowCardCount = 0;
    (*this).redCardCount = 0;
    for (int i = 0; i < 40; i++)
        yellowCardList[i] = NULL;
    for (int i = 0; i < 40; i++)
        redCardList[i] = NULL;
}

// Copy constructor
Referee::Referee(const Referee& obj) {
    std::cout << "Referee Copy Constructor!\n";
    (*this).yellowCardCount = obj.yellowCardCount;
    (*this).redCardCount = obj.redCardCount;

    for (int i = 0; i < yellowCardCount; i++) {
        (*this).yellowCardList[i] = obj.yellowCardList[i];
    }

    for (int i = 0; i < redCardCount; i++) {
        (*this).redCardList[i] = obj.redCardList[i];
    }
}

// Destructor
Referee::~Referee() {
    std::cout << "Referee Destructor!\n";
}

// Getter methods for each data members
int Referee::getYellowCardCount() {
    return yellowCardCount;
}

int Referee::getRedCardCount() {
    return redCardCount;
}

// Methods
// Method to add a Player instance onto the Referee's yellow card list
bool Referee::addToYellowCardList(Player *p) {
    // Player isn't initially in yellow card list as far as we know
    bool isInList = false; 
    int playerIndex = -1; // Index in case player is in the list

    // Check through the whole list
    // Reason: As the players might be scattered in different parts of the list
    for (int i = 0; i < 40; i++) {
        // Check if player is at this index of the yellowCardList
        if (p == yellowCardList[i]) {
            playerIndex = i; // Save the player's index
            isInList = true;
            break; // Break out of the loop since we found player on the list
        } else continue;
    }

    // Check if player is in the list based of the previous check loop
    if (isInList == true) {
        // In case player is already in the list, remove player from 
        // yellowCardList and add player into the redCardList if possible
        // Return depends if the player is also on the redCardList
        // Return true if player wasn't; otherwise return false
        if (addToRedCardList(p) == 1) {
            yellowCardList[playerIndex] = NULL;
            yellowCardCount--;
            return true;
        } else return false;
    } else {
        // In case player isn't on the yellow card list
        // Check if the number of yellow cards is 40
        if (yellowCardCount == 40) {
            std::cout << "Limit reached of yellow card list!\n";
            return false; // Couldn't successfully add player to list
        } else {
            // Check through the list to find an empty position to add player
            for (int i = 0; i < 40; i++) {
                if (yellowCardList[i] == NULL) {
                    yellowCardList[i] = p;
                    yellowCardCount++;
                    std::cout << "Incremented yellow card count!\n";
                    return true; // Player successfully added to the list
                }
            }
        }
    }
    return false;
}

// Method to add a Player instance onto the Referee's red card list
bool Referee::addToRedCardList(Player *p) {
    // Player isn't initially in red card list as far as we know
    bool isInList = false;

    // Check through the whole list
    // Reason: As the players might be scattered in different parts of the list
    for (int i = 0; i < 40; i++) {
        // Check if player is at this index of the redCardList
        if (p == redCardList[i]) {
            isInList = true;
            break; // Break out of the loop since we found player on the list
        } else continue;
    }

    // Check if player is in the list based of the previous check loop
    if (isInList == true) {
        return false; // Player already in list
    } else {
        // In case player isn't on the red card list
        // Check if the number of red cards is 40
        if (redCardCount == 40) {
            std::cout << "Limit reached of red card list!\n";
            return false; // Couldn't successfully add player to list
        } else {
            // Check through the list to find an empty position to add player
            for (int i = 0; i < 40; i++) {
                if (redCardList[i] == NULL) {
                    redCardList[i] = p;
                    redCardCount++;
                    std::cout << "Incremented red card count!\n";
                    return true; // Player successfully added to the list
                }
            }
        }
    }
    return false;
}
/* ---------------------------------- */