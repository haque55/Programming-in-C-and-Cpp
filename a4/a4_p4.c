#include<stdio.h>
#include<string.h>

// Function takes an array of characters and returns an int that is the number
// of consonants in the array of characters
int count_consonants(char str[]);

int main() {
    int count = 0;
    char str[100];
    
    // Loop until we find get an empty string with \n as its only element
    while(1) {
        fgets(str, sizeof(str), stdin);
        if(str[0] == '\n') { // Check if the first element is newline
            break; // Stop execution of program
        }
        count = count_consonants(str);
        printf("Number of consonants=%d\n", count);
    }

    return 0;
}

int count_consonants(char str[]) {
    int i, count = 0;

    for(i = 0; str[i] != '\0'; i++) { // Loop through all positions
        // Check if str[i] is a letter
        if((str[i] >= 'A' && str[i] <= 'Z') || 
        (str[i] >= 'a' && str[i] <= 'z')) {
            // Check if it is a vowel
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' ||
            str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' ||
            str[i]=='O' || str[i]=='U') {
                continue;
            } else count++; // str[i] is a consonant
        } // Everything else is a number or symbol
    }
    
    return count;
}