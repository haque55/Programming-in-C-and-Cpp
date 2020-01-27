#include<stdio.h>

int main() {
	float a, b, h;
	
	// Input bases and heights
	scanf("%f", &a);
	getchar();
	scanf("%f", &b);
	getchar();
	scanf("%f", &h);
	getchar();
	
	// Calculate areas and assign them to respective float variables
	float squareArea = a * a;
	float rectangleArea = a * b;
	float triangleArea = 0.5 * (a * h);
	float trapezoidArea = 0.5 * h * (a + b);
	
	// Print areas
	printf("square area=%f\n", squareArea);
	printf("rectangle area=%f\n", rectangleArea);
	printf("triangle area=%f\n", triangleArea);
	printf("trapezoid area=%f\n", trapezoidArea);
	
	return 0;
}