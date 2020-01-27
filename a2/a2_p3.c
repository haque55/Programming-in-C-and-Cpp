#include<stdio.h>

int main() {
	int weeks, days, hours;
	
	// Input number of weeks, days and hours 
	scanf("%d", &weeks);
	getchar();
	scanf("%d", &days);
	getchar();
	scanf("%d", &hours);
	getchar();
	
	// Multiply weeks by 168 hours/week and days by 24 hours/day and sum them up
	printf("%d\n", (weeks * 168 + days * 24 + hours));
	
	return 0;
}