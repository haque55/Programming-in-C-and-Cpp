#include<stdio.h>
#include<math.h>

// Function returns an integer, takes 2 integers as input
// num is the number we want to check for its primality
// test is used to check for the remainder of division between num and test
// using recursion
int isPrime(unsigned int num, unsigned int test);

int main() {
    unsigned int x;

    scanf("%u", &x);

    // Dependng on the return value of isPrime, print respective statement
    // Run isPrime with sqrt(x) + 1 as second argument to raise efficiency
    if(isPrime(x, sqrt(x) + 1) == 1) {
        printf("%u is prime\n", x);
    } else printf("%u is not prime\n", x);
    
    return 0;
}

int isPrime(unsigned int num, unsigned int i) {
    // Primality test against 1
    if(num < 2) 
        return 0; // It is not a prime number
    if(num == 2)
        return 1;
    if (i == 1) { // Check if recursion case has arrived at 1
        return 1;
    } else {
        if (num % i == 0) // Check if reminader is 0
            return 0;
        else
            return isPrime(num, i - 1); // Recursive call to check agaisnt i-1
    }
}