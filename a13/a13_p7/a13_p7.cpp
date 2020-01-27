#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec(20);

    // Assign value 8 to all 20 elements of the vector
    for (int i = 0; i < 20; i++) {
        vec[i] = 8;
    }

    // Try block
    try {
        vec.at(20); // Access 21th element, which is at position 20
    }
    // Catch out_of_range error when trying to access invalid index
    catch (std::out_of_range& error) {
        std::cerr << error.what() << std::endl;
    }

    return 0;
}