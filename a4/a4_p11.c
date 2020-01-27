#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// Function that takes the address of the string and a character
// It returns an integer value that tells us how many times our character was
// encounterd in the string in a case insensitive manner
int count_insensitive(char *str, char c);

int main() {
    int i, count = 0;
    char test[5] = {'b','H','8','u','$'};
    char *temp, *str;
    temp = (char *) malloc(sizeof(char) * 50);

    if(temp == NULL) { // Check if malloc was successful on temp
        exit(1);
    }

    // Input characters until we meet newline and save them to temp
    scanf("%[^\n]%*c", temp);

    str = (char *) malloc(sizeof(char) * strlen(temp));

    if(str == NULL) { // Check if malloc was successful on str
        exit(1);
    }

    strcpy(str, temp);
    free(temp); // Deallocate memory at temp

    // Loop through the string
    for(i = 0; i < strlen(str); i++) {
        // Check if character at this postion is an uppercase letter
        if(str[i] >= 'A' && str[i] <= 'Z') { 
            str[i] = tolower(str[i]); // Lower the case of the character
        }
    }

    // Test for our function to see if it works
    // Loop through all 5 cases found in the array test
    for(i = 0; i < 5; i++) {
        count = count_insensitive(str, test[i]);
        printf("The character '%c' occurs %d times.\n", test[i], count);
    }
    
    return 0;
}

int count_insensitive(char *str, char c) {
    int i;
    int count = 0;
    char lowerC = tolower(c); // Lower the case of the character we search for
    for(i = 0; i < strlen(str); i++) {
        // Check if character of string matches the char we search for
        if(str[i] == lowerC) {
            count++; // Occurrence of character incremented by 1
        }
    }
    return count;
}