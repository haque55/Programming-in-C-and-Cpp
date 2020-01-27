#include <stdio.h>
#include <ctype.h> 
#include <stdlib.h>
#include <string.h>

// Function returns nothing, it takes a pointer to a char array and an int 
// which is the size of the array
// It replaces each lowercase char it finds with its uppercase equivalent
void upper(char *arr, int size);

// Function returns nothing, it takes a pointer to a char array and an int
// which is the size of the array
// It replaces each uppercase char it finds with its lowercase equivalent
void lower(char *arr, int size);

// Function returns nothing, it takes a pointer to a char array and an int
// which is the size of the array
// It replaces each uppercase char it finds with its lowercase equivalent
// and vice versa
void reverse(char *arr, int size);

// Function returns nothing, it takes a pointer to a char array and an int
// which is the size of the array
// It frees the memory of the array and ends the execution of the program
void quit(char *arr, int size);

int main() {
    int size;
    char *temp, *str, choice;
    temp = (char *) malloc(sizeof(char) * 100); // Temporary holder of string

    if(temp == NULL) { // Check if malloc was successful on temp
        exit(1);
    }

    // Input characters until we meet newline and save them to temp
    scanf("%[^\n]%*c", temp);

    str = (char *) malloc(sizeof(char) * strlen(temp));

    if(str == NULL) { // Check if malloc was successful
        exit(1);
    }

    strcpy(str, temp); // Copy string that we will be working with onto str
    free(temp); // Deallocate memory at temp
    size = strlen(str);    

    while(1) { // Infinite loop to accept new input
        scanf("%c", &choice);
        getchar();

        int num = choice - '0'; // "Convert" digit char to its int equivalent

        // Function pointer array to map to one of the functions
        void (*funcArr[4])(char *, int) = {upper, lower, reverse, quit};

        // Call desired function
        (*funcArr[num - 1])(str, size);
    }
    return 0;
}

void upper(char *arr, int size) {
    int i;
    char *strCopy = (char *) malloc(sizeof(char) * size);
    if(strCopy == NULL) // Check if malloc was successful
        exit(1);
    strcpy(strCopy, arr);
    // Loop through the string
    for(i = 0; i < size; i++) {
        // Check if character at this postion is a lowercase letter
        if(strCopy[i] >= 'a' && strCopy[i] <= 'z') { 
            strCopy[i] = toupper(strCopy[i]); // Upper the case of the character
        }
    }
    printf("%s\n", strCopy);
    free(strCopy);
}

void lower(char *arr, int size) {
    int i;
    char *strCopy = (char *) malloc(sizeof(char) * size);
    if(strCopy == NULL) // Check if malloc was successful
        exit(1);
    strcpy(strCopy, arr);
    // Loop through the string
    for(i = 0; i < size; i++) {
        // Check if character at this postion is an uppercase letter
        if(strCopy[i] >= 'A' && strCopy[i] <= 'Z') { 
            strCopy[i] = tolower(strCopy[i]); // Lower the case of the character
        }
    }
    printf("%s\n", strCopy);
    free(strCopy);
}

void reverse(char *arr, int size) {
    int i;
    char *strCopy = (char *) malloc(sizeof(char) * size);
    if(strCopy == NULL) // Check if malloc was successful
        exit(1);
    strcpy(strCopy, arr);
    for(i = 0; i < size; i++) {
        // Check if character at this postion is an uppercase letter
        if(strCopy[i] >= 'A' && strCopy[i] <= 'Z') { 
            strCopy[i] = tolower(strCopy[i]); // Lower the case of the character
        } else if(strCopy[i] >= 'a' && strCopy[i] <= 'z') { // Check lowercase
            strCopy[i] = toupper(strCopy[i]); // Upper the case of the character
        }
    }
    printf("%s\n", strCopy);
    free(strCopy);
}

void quit(char *arr, int size) {
    free(arr);
    exit(1);
}