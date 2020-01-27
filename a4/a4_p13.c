#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*
    Functions get an array of characters as input and return nothing
    uppcase replaces every lowercase char with respective uppercase char 
    while lowcase does the opposite
*/
void uppcase(char *str);
void lowcase(char *str);

int main() {
    char str[90];

    while(1) {
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = '\0'; // Place a null terminator in place of \n
        if(strcmp(str, "exit") == 0) { // Check if string matches "exit"
            break; // Stop execution of program
        }
        uppcase(str);
        lowcase(str);
    }
    return 0;
}

void uppcase(char *str) {
    int i;
    for(i = 0; i < strlen(str); i++) { // Loop through the array
        if(islower(str[i])) // Check if we have lowercase characters
            str[i] = toupper(str[i]); // Change them to uppercase characters
    }
    printf("uppcase=%s\n", str);
}

void lowcase(char *str) {
    int i;
    for(i = 0; i < strlen(str); i++) { // Loop through the array
        if(isupper(str[i])) // Check if we have uppercase characters
            str[i] = tolower(str[i]); // Change them to lowercase characters
    }
    printf("lowcase=%s\n", str);
}