#include<stdio.h>

// Function returns nothing, it takes an integer as input
// It prints out a count down from n to 1 by using recursion
void countDown(int n) {
    if(n == 1) { // Print and call itself only if n >= 1
        printf("1\n");
    } else {
        printf("%d\n", n);
        countDown(n - 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    countDown(n);
    
    return 0;
}