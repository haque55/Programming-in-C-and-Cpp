#include <stdio.h>
#include "stack.h"

int main() {
    char ch;
    int num;
    struct stack Stack;
    Stack.count = 0; // count holds the number of elements in the stack

    while(1) { // Infinite loop to accept new commands
        scanf("%c*c", &ch);
        switch(ch) {
            case 's':
                scanf("%d", &num);
                getchar();
                push(&Stack, num);
                break;
            case 'p':
                pop(&Stack);
                break;
            case 'e':
                empty(&Stack);
                break;
            case 'q':
                printf("Quit\n");
                return 0;
        }
    }
    return 0;
}