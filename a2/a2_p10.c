#include<stdio.h>

int main() {
	int n;
	int i = 1; // Initialize iterating variable

	// Accept input only if n is bigger than 0
	do {
		scanf("%d", &n);
		getchar();
	} while(n <= 0);
	
	
	while(i != n + 1) { // Iterate until i is n + 1
		if(i == 1) // Modify output to print "day" instead of "days" when i=1
			printf("%d day = %d hours\n", i, i * 24);
		else
			printf("%d days = %d hours\n", i, i * 24);
		
		i = i + 1;
	}
	
	return 0;
}