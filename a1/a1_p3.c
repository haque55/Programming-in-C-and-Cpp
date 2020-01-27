// There was a missing # in the include statement for the preprocessor
#include <stdio.h>

int main() {
	float result; /* The result of the division */
	int a = 5;
	
	// Assigning a floating point value to an int results in the 
	// value being truncated down to the nearest integer in this case 13
	// To solve this, change the type of the variable to match the value
	float b = 13.5;
	
	// Result has a floating point number as a value from
	// the division between an int and a float
	result = a / b;
	
	// Initial statement wanted to receive an integer data type as an argument
	// Our result is a float data type
	// To solve this, chnage the type that the printf statement is expecting to
	// match our result data type
	printf("The result is %f\n", result);
	
	return 0;
}