#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {
    char *temp, *str;
    struct stack Stack;

    while(1) { // Infinite loop to accept new input
        // Counter is the number of successful comparisons between words
        int counter = 0; 
        Stack.count = 0; // count holds the number of elements in the stack

        // Maximum input size of each sentece set to 1500 (50 * 30)
        temp = (char *) malloc(sizeof(char) * 1500);
        if (temp == NULL) // Check if malloc was successful on temp
            exit(1);

        scanf("%[^\n]%*c", temp);
        
        str = (char *) malloc(sizeof(char) * strlen(temp));

        if (str == NULL) // Check if malloc was successful on str
            exit(1);

        strcpy(str, temp);
        free(temp); // Deallocate memory at temp

        if (strcmp(str, "exit") == 0)
            return 0;
        
        // Returns first token 
        char* token = strtok(str, " "); 
    
        // Keep pushing words onto the Stack until we find no mroe delimiters 
        while (token != NULL) {
            push(&Stack, token);
            token = strtok(NULL, " "); 
        }

        checkPalindrome(&Stack, &counter);
        empty(&Stack);
    }
    return 0;
}