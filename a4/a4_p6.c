#include<stdio.h>
#include<stdlib.h>

// Function takes an array and an integer as input
// It returns nothing, it finds the two greatest values in the array and it
// prints them on the screen
void twoGreatest(int arr[], int size) {
    int i; 
    int biggest = arr[0], secondBiggest = arr[0];

    // Loop from 2nd element to the last one in the array
    for(i = 1; i < size; i++) {
        if(arr[i] > biggest) { // Check if element is bigger than biggest
            // Value of biggest assigned to secondBiggest
            secondBiggest = biggest;
            biggest = arr[i]; // Biggest assigned value of element
        } 
        // Check if it is bigger than secondBiggest and smaller than biggest
        else if (arr[i] > secondBiggest) {  
            secondBiggest = arr[i];
        }
    }

    printf("Biggest value in the array: %d\n", biggest);
    printf("Second biggest value in the array: %d\n", secondBiggest);
}

int main() {
    int size, *dynArr, i;

    scanf("%d", &size);
    dynArr = (int *) malloc(sizeof(int) * size);

    if(dynArr == NULL) { // Check if malloc was successful
        exit(1);
    }

    // Input elements into the dynamic array
    for(i = 0; i < size; i++) {
        scanf("%d", &dynArr[i]);
    }

    twoGreatest(dynArr, size);

    free(dynArr);

    return 0;
}