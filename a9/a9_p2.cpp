#include <iostream>

int main(int argc, char **argv) {
    int n;
    double x;
    std::string s;

    std::cin >> n >> x >> s;
    
    // Loop n times and output string:double every time
    for (int i = 0; i < n; i++) {
        std::cout << s << ":" << x << std::endl;
    }
    
    return 0;
}