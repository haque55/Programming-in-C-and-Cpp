#include<stdio.h>

// Macro checkbit defined that takes an argument
// If the mask 1 AND argument give a result bigger than 0, print 1
// If result is 0, print 0
#define checkbit(c) {if((c & 1) == 1) printf("1\n"); else printf("0\n");}

int main() {
    unsigned char uc;

    scanf("%c", &uc);

    printf("The decimal representation is: %d\n", uc);
    printf("The least significant bit is: ");
    checkbit(uc); // Call macro with argument uc

    return 0;
}