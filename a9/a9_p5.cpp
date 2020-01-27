#include <iostream>

int main(int argc, char **argv) {
    char buffer[100];
    std::string temp, concatString;
    std::string exit = "exit";

    // Input first string
    std::cin.getline(buffer, 100);
    // boolean value to hold the comparison between buffer and the "exit"
    bool notExit = (buffer != exit);  

    // While-loop that runs until the entered string matches "exit"
    while (notExit) {
        temp = std::string(buffer); // Temp holds the string
        concatString.append(temp); // Append temp to concatString
        std::cin.getline(buffer, 100); // Read the following string
        notExit = buffer != exit; // Check if it matches "exit"
    }

    std::cout << concatString << std::endl; // Output concatenated string

    return 0;
}