#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function returns nothing, takes 3 arrays of chars and 2 integers
// Function stores in arr the concatenation of str1 and str2
// Integers store the values of str1 and str2 respectively
// Function prints the concatenated string into stdout
void concatenate(char arr[], char str1[], int size1, char str2[], int size2);

int main() {
    char str1[100], str2[100], *dynArr;
    
    scanf("%[^\n]%*c", str1);
    scanf("%[^\n]%*c", str2);

    // Allocate memory equal to sizeof(char) * sum of lengths of strings
    dynArr = (char *) malloc(sizeof(char) * (strlen(str1) + strlen(str2)));

    if(dynArr == NULL) { // Check if malloc was successful
        exit(1);
    }

    concatenate(dynArr, str1, strlen(str1), str2, strlen(str2));

    free(dynArr);
    return 0;
}

void concatenate(char arr[], char str1[], int size1, char str2[], int size2) {
    int i;
    // Assign each respective postion from str1 to arr
    for(i = 0; i < size1; i++) {
        arr[i] = str1[i];
    }
    // Starting from pos size1 until size1+size2 which is the sum of both
    // lengths of the strings
    // In order to assign each respective char from str2 to arr
    // We access each element of str2 using i-size1 since i = size1
    for(i = size1; i < (size1+size2); i++) {
        arr[i] = str2[i - size1];
    }
    arr[size1+size2] = '\0'; // Place null terminator after concatenation

    printf("Result of concatenation: %s\n", arr);
}