#include <iostream>
#include "TournamentMember.h"

/*
    In order to make it work, you have to input the information the way that it
    is instructed in stdout by the cout commands. Here are some already made
    Players to input into stdout:

Player First 1900-00-00 Rome Player 10 Striker 7 Left
Player Second 1925-00-00 Bremen Player 21 Centre-Back 2 Right
Player Third 1950-00-00 Sydney Player 23 Full-Back 1 Right

*/
int main(int argc, char** argv) {
    std::string outputDecorate = "*------------------*\n";

    std::cout << outputDecorate;

    Player *players[100];
    Referee referee;

    int playerNumber;
    std::cout << "Input the number of players in the tournament: ";
    std::cin >> playerNumber;

    // Initialize each player with user given input
    for (int i = 0; i < playerNumber; i++) {
        // Default values set for each player
        std::string firstname = "Default";
        const char *firstName = firstname.c_str();
        std::string lastname = "Default";
        const char *lastName = lastname.c_str();
        std::string dateofbirth = "0000-00-00";
        const char *dateOfBirth = dateofbirth.c_str();

        std::string location, role, position, dominantFoot;
        int number, goalsScored;

        std::cout << "Input information for player in the following order "
                  << "(First Name, Last Name, DOB, Location, Role, Number,"
                  << " Position, Number of goals scored, Dominant Foot):\n";

        std::cin >> firstname >> lastname >> dateofbirth >> location >> role 
                 >> number >> position >> goalsScored >> dominantFoot;
        // Set each data member using the input given
        players[i] = new Player(firstName, lastName, dateOfBirth, location, 
                                role, true, number, position, goalsScored, 
                                dominantFoot);
    }    

    while (1) {
        std::cout << "Give player index in player array to give a card: ";
        int playerPosition; // Position of player in players array
        std::cin >> playerPosition;
        if (playerPosition < 0 || playerPosition > playerNumber - 1) {
            std::cout << "Wrong input of player index! Try program again!\n";
            break;
        } else {
            bool result; // Save return value of addToRedCardList()
            std::string cardIdentifier; // Variable to hold given card
            std::cout << "Give desired card using \"red\" or \"yellow\": ";
            std::cin >> cardIdentifier;

            // Depending on the input, Referee gives different cards
            if (cardIdentifier == "red") {
                result = referee.addToRedCardList(players[playerPosition]);
                if (result == false) {
                    std::cout << "addToRedCardList returned false!\n";
                    continue;
                }
                std::cout << "Red card count: " 
                          << referee.getRedCardCount()
                          << std::endl;
            } else if (cardIdentifier == "yellow") {
                result = referee.addToYellowCardList(players[playerPosition]);
                if (result == false && referee.getYellowCardCount() == 40)
                    break; // Can not add any more players onto the list
                std::cout << "Yellow card count: "
                          << referee.getYellowCardCount()
                          << std::endl;
            } else std::cout << "Wrong card identifier! Try again!\n";
        }
    }

    // Delete each dynamically allocated Player
    for (int i = 0; i < playerNumber; i++)
        delete players[i];

    return 0;
}