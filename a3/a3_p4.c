#include <stdio.h>
int position(char str[], char c) {
    int idx;
    /* Loop until end of string */
    // Increment the iterator until we find the 'g' or '\0'
    for (idx = 0; str[idx] != c && str[idx] != '\0'; ++idx) {
        /* do nothing */
        /*
            It only printed 0 every time because on the first iteration of the
            for-loop, we returned an integer value which was our iterator idx
            This was due to the return statement being part of the loop
            as the first statement after the for-loop which had no braces to
            enclose the for-loop body
        */
    }
    return idx; // Return the position we stopped at
}

int main() {
    char line[80];
    while (1)
    {
        printf("Enter string:\n");
        fgets(line, sizeof(line), stdin);
        printf("The first occurrence of 'g' is: %d\n", position(line, 'g'));
        break; // break out of the infinite loop after outputting the answer
    }
    return 0;
}