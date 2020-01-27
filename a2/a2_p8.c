#include<stdio.h>

int main() {
	int number;
	
	scanf("%d", &number);
	
	// Check if remainder is 0 in both cases when dividing by 2 and 7
	if((number % 2 == 0) && (number % 7 == 0)) {
		printf("The number is divisible by 2 and 7\n");
	} else printf("The number is NOT divisible by 2 and 7\n");
	
	return 0;
}