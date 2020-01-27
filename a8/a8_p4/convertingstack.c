#include <stdio.h>
#include <math.h>
#include "stack.h"

int main() {
    int i, remainder;
    unsigned int num;
    struct stack Stack;
    Stack.count = 0; // count holds the number of elements in the stack

    // Input number to convert to binary
    scanf("%u", &num);
    unsigned int temp = num;

    // Loop until 2^i is bigger than our number
    for(i = 0; pow(2, i) < num; i++) {
        // Calculate remainder on each step and push that onto Stack
        remainder = temp % 2;
        push(&Stack, remainder);
        temp = temp / 2;
    }

    printf("The binary representation of %u is ", num);

    // Loop until 2^i is bigger than our number
    for(i = 0; pow(2, i) < num; i++) {
        // Pop each element of the Stack which outputs it into stdout
        pop(&Stack);
    }
    printf(".\n");

    return 0;
}