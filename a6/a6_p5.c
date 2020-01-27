#include<stdio.h>
#include<math.h>

int main() {
    unsigned char uc, temp;
    int i, decimal = 0;

    scanf("%c", &uc);
    temp = uc;

    // Iterate through all 8 bits of char
    for(i = 0; i < 8; i++) {
        // Check with bit mask if bit 1 is set
        if(temp & 1) {
            // Add value of 2^i to decimal sum in case that bit 1 is 1
            decimal += pow(2, i);
        }
        // Right shift by 1 to check next bit on next iteration
        temp = temp >> 1;
    }

    temp = uc; // Reassign the value of uc to temp

    printf("The decimal representation is: %d\n", decimal);
    printf("The backwards binary representation is: ");

    // Iterate through all 8 bits of char
    for(i = 0; i < 8; i++) {
        // Print something only if we haven't surpassed the limit of decimal 
        // value by using 2^i in the position we are at
        if(pow(2,i) <= decimal) {
            // Check if bit 1 is set and print corresponding value
            if((temp & 1) == 1) 
                printf("1");
            else printf("0");
            // Right shift by 1 to check next bit on next iteration
            temp = temp >> 1;
        }
    }
    printf("\n"); // New line after printing reverse binary representation

    return 0;
}