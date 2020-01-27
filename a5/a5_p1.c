#include<stdio.h>

// Function returns nothing, takes an integer and a char as input
// It prints a triangle made of the char with height n
void triangleOfChars(int n, char ch);

int main() {
    int n;
    char ch;

    scanf("%d%*c", &n);
    scanf("%c", &ch);

    triangleOfChars(n, ch);

    return 0;
}

void triangleOfChars(int n, char ch) {
    int i;
    // Check if n (representative of number of rows and repetitions of char)
    // is bigger than 0
    if(n > 0) {
        for(i = n; i > 0; i--) { // Print n times the char on each row
            printf("%c", ch);
        }
        printf("\n"); // Print newline when we arrive at the end of the row
        // Recursive call to print next row with n-1 chars
        triangleOfChars(n - 1, ch);
    }
}