#include<stdio.h>
#include<string.h>

// Function takes an address to an array of chars and 2 characters
// It returns nothing and it replaces all occurrences of first char in the array
// with the second char
void replaceAll(char *str, char c, char e);

int main() {
    char c, e, str[80];

    while(1) {
        fgets(str, sizeof(str), stdin);
        str[strlen(str) - 1] = '\0'; // Place a null terminator in place of \n
        if(strcmp(str, "stop") == 0) { // Check if string matches "stop"
            break; // Stop execution of program
        }
        scanf("%c", &c);
        getchar();
        scanf("%c", &e);
        getchar();

        // Print char to be replaced, replacing char and string before
        printf("%c\n%c\n%s\n", c, e, str);
        replaceAll(str, c, e);
        printf("%s\n", str); // Print string after replaceAll
    }
    return 0;
}

void replaceAll(char *str, char c, char e) {
    int i;
    for(i = 0; i < strlen(str); i++) { // Loop through the elements of the array
        if(str[i] == c) { // Check if element matches char to be replaced
            str[i] = e; // Place replacing char
        }
    }
}