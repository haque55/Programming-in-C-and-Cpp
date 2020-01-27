#include<stdio.h>

float convert(int cm);

int main() {
	int cm;
	float km;
	
	scanf("%d", &cm);
	
	// Assign the return value of convert() to float km
	km = convert(cm);
	
	printf("Result of conversion: %f\n", km);
	
	return 0;
}

// Function of type float to convert integer argument cm to float km and return
// it after dividing by 100000
float convert(int cm) {
	float km = cm / 100000.0;
	return km;
}