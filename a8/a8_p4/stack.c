#include <stdio.h>
#include <limits.h>
#include "stack.h"

void push(struct stack *Stack, int number) {
    // printf("Pushing ");
    if((*Stack).count == 32) // Check if stack is full
        printf("Stack Overflow\n");
    else {
        // printf("%d\n", number);
        (*Stack).array[(*Stack).count] = number; // Place value inside stack
        (*Stack).count++;
    }
}

void pop(struct stack *Stack) {
    // printf("Popping ");
    if(isEmpty(Stack) == 1) // Check if stack is empty with isEmpty
        printf("Stack Underflow\n");
    else {
        printf("%d", (*Stack).array[(*Stack).count - 1]);
        // Popped off element to UINT_MAX (can be removed as it's not necessary)
        (*Stack).array[(*Stack).count - 1] = UINT_MAX; 
        (*Stack).count--;
    }
}

void empty(struct stack *Stack) {
    printf("Emptying Stack ");
    for(int i = (*Stack).count - 1; i >= 0; i--){
        printf("%d ", (*Stack).array[(*Stack).count - 1]);
        (*Stack).array[(*Stack).count - 1] = UINT_MAX;
        (*Stack).count--;
    }
    printf("\n");
}

int isEmpty(struct stack *Stack) {
    if((*Stack).count == 0)
        return 1;
    else return 0;
}