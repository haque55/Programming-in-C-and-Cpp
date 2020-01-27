#include<stdio.h>
#include<string.h>

// Function takes an address of the array where the string is stored and it
// returns an integer that is the number of consonants in the string
int count_consonants(char *init);

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

int count_consonants(char *init) {
    int i, count = 0;
    
    for(i = 0; (*(init + i)) != '\0'; i++) { // Loop through all positions
        // Check if str[i] is a letter
        if(((*(init + i)) >= 'A' && (*(init + i)) <= 'Z') ||
        ((*(init + i)) >= 'a' && (*(init + i)) <= 'z')) {
            // Check if  it is a vowel
            if((*(init + i))=='a' || (*(init + i))=='e' || (*(init + i))=='i' ||
             (*(init + i))=='o' || (*(init + i))=='u' || (*(init + i))=='A' || 
             (*(init + i))=='E' || (*(init + i))=='I' || (*(init + i))=='O' || 
             (*(init + i))=='U') {
                continue;
            } else count++; // str[i] is a consonant
        } // Everything else is a number or symbol
    }
    
    return count;
}