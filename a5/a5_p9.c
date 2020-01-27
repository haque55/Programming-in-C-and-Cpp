#include<stdio.h>
#include<stdlib.h>

// Function returns nothing, it takes a triple pointer and 3 integers
// Integers represent the dimensions of the dynamically allocated 3D-array
// Function takes input from stdin and stores them as elements in the 3D-array
void read(int ***arr, int x, int y, int z);

// Function returns nothing, it takes a triple pointer and 3 integers
// Integers represent the dimensions of the dynamically allocated 3D-array
// Function print the 2D-sections of the multidimensional array parallel
// to the XOY axis
void print2DSections(int ***arr, int x, int y, int z);

int main() {
    int i, j, x, y, z, ***dynArr;

    scanf("%d%d%d", &x, &y, &z);

    dynArr = (int ***) malloc(sizeof(int **) * x);
    if(dynArr == NULL) { // Check if malloc was successful
        exit(1);
    }

    for(i = 0; i < x; i++) {
        dynArr[i] = (int **) malloc(sizeof(int *) * y);
        // Check if each array of pointers was successfully allocated
        if(dynArr[i] == NULL) {
            exit(1);
        }
        for(j = 0; j < y; j++) {
            dynArr[i][j] = (int *) malloc(sizeof(int) * z);
            // Check if each array was successfully allocated
            if(dynArr[i][j] == NULL) {
                exit(1);
            }
        }
    }

    read(dynArr, x, y, z);
    print2DSections(dynArr, x, y, z);

    // Deallocate memory
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            free(dynArr[i][j]); // from pointers of arrays
        }
        free(dynArr[i]); // from pointers of pointers of arrays
    }
    free(dynArr); // from triple pointer
    
    return 0;
}

void read(int ***arr, int x, int y, int z) {
    int i, j, k;
    for(i = 0; i < x; i++) {
        for(j = 0; j < y; j++) {
            for(k = 0; k < z; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
}

void print2DSections(int ***arr, int x, int y, int z) {
    int i, j, k;
    // Outer loop goes through layers of depth
    for(k = 0; k < z; k++) {
        printf("Section %d:\n", k + 1); // State which layer we are on
        for(i = 0; i < x; i++) { // Loop through rows
            for(j = 0; j < y; j++) { // Loop through columns
                printf("%d ", arr[i][j][k]);
            }
            printf("\n");
        }
    }
}