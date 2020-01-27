#include<stdio.h>

// Function returns nothing, takes an array of floats and an integer as input
// The integer represents the number of elements of the array
// Function divides each value of the array by 5 and assigns values to
// respective element position inside the array
void divby5(float arr[], int size);

int main() {
    int i;
    float arr[]= {5.5, 6.5, 7.75, 8.0, 9.6, 10.36};
    int size = sizeof(arr) / sizeof(float); // Calculate number of elements

    printf("Before:\n");
    // Print each float with up to 3 decimal digit precision before division
    for(i = 0; i < size; i++) {
        printf("%.3f ", arr[i]);
    }

    divby5(arr, size);

    printf("\nAfter:\n");
    // Print each float with up to 3 decimal digit precision after division
    for(i = 0; i < size; i++) {
        printf("%.3f ", arr[i]);
    }
    printf("\n");

    return 0;
}

void divby5(float arr[], int size) {
    int i;
    for(i = 0; i < size; i++) { // Loop through the array
        // Divide element by 5 and assign value to the element
        arr[i] = arr[i] / 5;
    }
}