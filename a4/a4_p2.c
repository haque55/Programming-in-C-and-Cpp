#include<stdio.h>

int main() {
    int i = 0;
    char str[50];
    scanf("%[^\n]%*c", str); // Accept input until we meet newline character


    while(str[i] != '\0') { // If we haven't arrived at the end of the string
        // If i is even, print a space then the char inside str[i]
        if(i % 2 == 1) {
            printf(" %c\n", str[i]);
        } else printf("%c\n", str[i]); // Else print without space in front
        i++;
    }

    return 0;
}