#include<stdio.h>

int main() {
    float x;
    int n, i;
	
	scanf("%f", &x);
	getchar();

    scanf("%d", &n);
    getchar();
    
    // Cycle until input for n is a valid integer value
    while(n <= 0) {
        printf("Input is invalid, reenter value\n");
        scanf("%d", &n);
        getchar();
    }

	// Print the float n times by iterating from 0 until n (inclusive)
    for(i = 0; i < n; i++) {
        printf("%f\n", x);
    }

    return 0;
}