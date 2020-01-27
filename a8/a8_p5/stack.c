#include <stdio.h>
#include <string.h>
#include "stack.h"

void push(struct stack *Stack, char *ptrWord) {
    if ((*Stack).count == 50) // Check if stack is full
        printf("Limit of words to input!\n");
    else {
        (*Stack).array[(*Stack).count] = ptrWord; // Place value inside stack
        (*Stack).count++;
    }
}

void checkPalindrome(struct stack *Stack, int *counter) {
    int i;
    // Iterate until the half of the stack or 1 less than half of the stack
    // if the number of words is odd
    for (i = 0; i < ((*Stack).count / 2); i++) {
        // Pointers that iterate through each word from both sides to the middle
        // of the sentence
        char *iterateFromStart = (*Stack).array[i];
        char *iterateFromEnd = (*Stack).array[(*Stack).count - i - 1];
        // Check if both words are the same
        if (strcmp(iterateFromStart, iterateFromEnd) == 0)
            (*counter)++;
    }
    if (*counter == ((*Stack).count / 2))
        printf("The sentence is palindromic by words!\n");
    else printf("The sentence is not palindromic by words!\n");
}

void empty(struct stack *Stack) {
    for (int i = (*Stack).count - 1; i >= 0; i--){
        // Set each char pointer to NULL and reduce count of elements in stack
        (*Stack).array[(*Stack).count - 1] = NULL;
        (*Stack).count--;
    }
}