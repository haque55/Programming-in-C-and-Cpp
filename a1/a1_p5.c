#include<stdio.h>
int main () {
	// Declare and initiliaze variables
    int x = 2138;
    float y = -52.358925;
    char z = 'G';
    double u = 61.295339687;
    
    printf("x=%9d\n", x); // Output x over 9 positions
    printf("y=%11.5f\n", y); // Output y over 11 positions with precision up to 5 digits
    printf("z=%c\n", z); // Output c as a character
    printf("u=%.7lf\n", u); // Output u with precision up to 7 digits
    
    return 0;
}