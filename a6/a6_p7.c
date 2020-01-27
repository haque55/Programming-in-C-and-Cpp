#include<stdio.h>
#include<math.h>

// Function returns an unsigned char, takes 1 unsigned char and 3 ints as input
// It sets 3 bits of unsigned char at positions given by the 3 ints and it
// returns the modified unsigned char 
unsigned char set3bits(unsigned char uc, int fstbit, int sndbit, int trdbit);

int main() {
    unsigned char uc, temp, setChar;
    int fstbit, sndbit, trdbit, decimal = 0, i;

    scanf("%c", &uc);
    scanf("%d%d%d", &fstbit, &sndbit, &trdbit);

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
    printf("The binary representation is: ");

    // Iterate through all 8 bits of char
    for(i = 7; i >= 0; i--) {
        // Right shift to the corresponding bit to print the correct bit value
        temp = temp >> i;
        // Check if bit 1 is set and print corresponding value
        if((temp & 1) == 1) 
            printf("1");
        else printf("0");
        // Reassign uc to temp
        temp = uc;
    }
    printf("\n"); // New line after printing binary representation

    setChar = set3bits(uc, fstbit, sndbit, trdbit);
    temp = setChar;

    printf("After setting the bits: ");

    // Iterate through all 8 bits of char
    for(i = 7; i >= 0; i--) {
        // Right shift to the corresponding bit to print the correct bit value
        temp = temp >> i;
        // Check if bit 1 is set and print corresponding value
        if((temp & 1) == 1) 
            printf("1");
        else printf("0");
        // Reassign setChar to temp
        temp = setChar;
    }
    printf("\n"); // New line after printing binary representation

    return 0;
}

unsigned char set3bits(unsigned char uc, int fstbit, int sndbit, int trdbit) {
    // Left shift 1 by the corresponding argument and apply bitwise OR to 
    // turn that bit on
    uc = (uc | (1 << fstbit));
    uc = (uc | (1 << sndbit));
    uc = (uc | (1 << trdbit));
    return uc;
}