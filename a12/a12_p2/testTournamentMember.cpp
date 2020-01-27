#include <iostream>
#include "TournamentMember.h"

int main(int argc, char** argv) {
    const char firstName[36] = "Johnny";
    char lastName[37] = "English";
    char date[11] = "1950-12-31";
    std::string location = "London";
    std::string updatedLocation = "Monaco";
    std::string role = "Player";
    bool active = true;

    std::string outputDecorate = "*------------------*\n";

    std::cout << outputDecorate;

    // Default constructed instance
    TournamentMember firstInstance;
    firstInstance.printInformation();

    std::cout << outputDecorate;

    // Parametric constructed instance
    TournamentMember secondInstance(firstName, lastName, date, location, role,
                                    active);
    secondInstance.printInformation();

    std::cout << outputDecorate;

    // Change static data member location
    secondInstance.updateLocation(updatedLocation);

    std::cout << outputDecorate;

    // Show the TournamentMember instance data members after location changed
    secondInstance.printInformation();

    std::cout << outputDecorate;

    // Copy constructed instance
    TournamentMember thirdInstance(secondInstance);
    thirdInstance.printInformation();

    std::cout << outputDecorate;
    return 0;
}