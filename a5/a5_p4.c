#include<stdio.h>
#include<stdlib.h>

// Function returns nothing, takes an array of floats and an integer as input
// The integer represents the number of elements of the array
// Function divides each value of the array by 5 and assigns values to
// respective element position inside the array
void divby5(float arr[], int size);

int main() {
    int i, size;
    float *dynArr;

    scanf("%d", &size);

    dynArr = (float *) malloc(sizeof(float) * size);

    if(dynArr == NULL) { // Check if malloc was successful
        exit(1);
    }

    // Loop for accepting input
    for(i = 0; i < size; i++) {
        scanf("%f", &dynArr[i]);
    }
    
    printf("Before:\n");
    // Print each float with up to 3 decimal digit precision before division
    for(i = 0; i < size; i++) {
        printf("%.3f ", dynArr[i]);
    }

    divby5(dynArr, size);

    printf("\nAfter:\n");
    // Print each float with up to 3 decimal digit precision after division
    for(i = 0; i < size; i++) {
        printf("%.3f ", dynArr[i]);
    }
    printf("\n");

    free(dynArr);
    
    return 0;
}

void divby5(float arr[], int size) {
    int i;
    for(i = 0; i < size; i++) { // Loop through the array
        // Divide element by 5 and assign value to the element
        arr[i] = arr[i] / 5;
    }
}