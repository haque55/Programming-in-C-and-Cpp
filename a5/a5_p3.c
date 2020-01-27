#include<stdio.h>
#include<ctype.h>

// Function returns an integer value, takes a pointer to an array of chars as 
// input
// The number of lowercase letters in the array is the integer that is returned
int count_lower(char* str);

int main() {
    char str[50];
    int countLower;

    // Loop until we find get an empty string with \n as its only element
    while(1) {
        fgets(str, sizeof(str), stdin);
        if(str[0] == '\n') { // Check if the first element is newline
            break; // Stop execution of program
        }
        countLower = count_lower(str);
        printf("%d\n", countLower);
    }
    
    return 0;
}

int count_lower(char* str) {
    int i, count = 0;
    for(i = 0; (*(str+i)) != '\0'; i++) { // Loop until we find null terminator
        if(islower((*(str+i)))) // Check if char is lowercase
            count++;
    }
    return count;
}