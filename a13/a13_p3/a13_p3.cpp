#include <iostream>
#include <fstream>

int main() {
    int n;

    std::cout << "Enter the number of files to be read: ";
    std::cin >> n;
    std::string filename;

    // Open the output file in binary and truncate it upon opening
    std::ofstream out("concatn.txt", std::ios::binary | std::ios::trunc);
    if (!out.good()) { // Check if it didn't open successfully
        std::cerr << "Error opening output file!" << std::endl;
        exit(2);
    }
    
    // Loop to go through each file
    for (int i = 0; i < n; i++) {
        std::cin >> filename;
        std::ifstream in(filename, std::ios::binary);
        if (!in.good()) { // Check if it didn't open successfully
            std::cerr << "Error opening input file " 
                      << filename
                      << "!"
                      << std::endl;
            exit(2);
        }

        if (in.is_open() && out.is_open()) { // Check if both files are open
            // Two methods to copy file, one using a library function rdbuf
            // and the other by using a char buffer equal to size of file read
            // Method 1
            /*
                out << in.rdbuf();
                // Place end of line character after content copy
                out << std::endl;
            */

            // Method 2
            in.seekg(0, std::ios::end); // Go to end of file
            int fileLength = in.tellg(); // Store file length
            in.seekg(0, std::ios::beg); // Go to beginning of file

            // Dynamically allocated char array to store entire file
            char *buf = new char[fileLength];

            in.read(buf, fileLength); // Read whole file from in into buf
            out.write(buf, fileLength); // Write whole file from buf into out

            // Place end of line character after content copy
            out << std::endl;

            delete [] buf;
        }
        in.close(); // Close input file
    }
    out.close(); // Close output file
    return 0;
}