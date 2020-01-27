#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
    char c;
    std::string input, filename, extension;
    char delimiter = '.';

    std::cout << "Enter file name: ";
    std::cin >> input;

    // Find position of period in input
    std::size_t found = input.find_last_of(delimiter);

    // Divide the input into filename and extension using the position of period
    filename = input.substr(0, found);
    extension = input.substr(found, input.length());

    // Assign the new name of the file to be copied into by concatenating
    // filename, "_copy" and the extension
    std::string result = filename + "_copy" + extension;

    // Open the in file
    std::ifstream in(input);
	if (!in.good()) { // Check if it didn't open successfully
		std::cerr << "Error opening input file!" << std::endl;
		exit(1);
	}

    // Open the out file with truncate flag
	std::ofstream out(result, std::ios::trunc);
	if (!out.good()) { // Check if it didn't open successfully
		std::cerr << "Error opening output file!" << std::endl;
		exit(2);
	}

    // Check if both files are open
    if (in.is_open() && out.is_open()) {
        // Extract the in file character by character
        while (in.get(c))
            out << c; // Insert each character into out
    } else std::cout << "At least one of the files couldn't be opened!";

    // Close files
	in.close(); 
	out.close();

    return 0;
}