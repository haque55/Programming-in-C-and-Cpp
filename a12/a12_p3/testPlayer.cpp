#include <iostream>
#include "TournamentMember.h"

int main(int argc, char** argv) {
    std::string outputDecorate = "*------------------*\n";

    std::cout << outputDecorate;
    
    // Player instance created using default constructor
    Player firstInstance;
    firstInstance.printInformation();
    firstInstance.printPlayerInformation(); // Show default data members
    
    std::cout << outputDecorate;

    // Set some data members to the firstInstance using setter functions 
    firstInstance.setDominantFoot("Left");
    firstInstance.setNumber(10);
    firstInstance.setPosition("Midfield");

    firstInstance.printInformation();
    firstInstance.printPlayerInformation(); // Show changed data members

    std::cout << outputDecorate;

    // c_str() used to return a constant char pointer of each string
    std::string firstname = "Virgil";
    const char *firstName = firstname.c_str();
    std::string lastname = "Van Dijk";
    const char *lastName = lastname.c_str();
    std::string dateofbirth = "1991-07-08";
    const char *dateOfBirth = dateofbirth.c_str();

    std::string location = "Liverpool";
    std::string role = "Player";
    std::string position = "Attacker";
    std::string foot = "Left";

    // Player instance created using parametric constructor
    Player secondInstance(firstName, lastName, dateOfBirth, location, role, 
                          true, 23, position, 4, foot);
    
    secondInstance.printInformation();
    secondInstance.printPlayerInformation();

    std::cout << outputDecorate;

    // Player instance created using copy constructor
    Player thirdInstance(secondInstance);

    thirdInstance.printInformation();
    thirdInstance.printPlayerInformation();

    std::cout << outputDecorate;

    TournamentMember::updateLocation("Copenhagen");

    std::cout << outputDecorate;

    // Output all the instances to see the changed location
    firstInstance.printInformation();
    firstInstance.printPlayerInformation();

    std::cout << outputDecorate;

    secondInstance.printInformation();
    secondInstance.printPlayerInformation();

    std::cout << outputDecorate;

    // Call the incrementGoalsScored method
    thirdInstance.incrementGoalsScored();

    // Show the changed goalsScored data member
    thirdInstance.printInformation();
    thirdInstance.printPlayerInformation();

    std::cout << outputDecorate;

    return 0;
}