#include<stdio.h>
#include<stdlib.h>

// Function returs nothing, takes a pointer to an array of pointers and 2 ints
// Integers represent the size of the 2D-array that is being dynamically
// allocated by the pointer and the pointers to the arrays
// It accepts input from stdin and places it in inside the arrays
void read(int **arr, int a, int b);

// Function returs nothing, takes a pointer to an array of pointers and 2 ints
// Integers represent the size of the 2D-array that is being dynamically
// allocated by the pointer and the pointers to the arrays
// Function prints out the elements of the 2D-array in a formatted form
void print(int **arr, int a, int b);

// Function returns nothing, takes 3 pointers to arrays of pointers and 3 ints
// a and b represent dimensions of first 2D-array
// b and c represent dimensions of second 2D-array
// a and c represent dimensions of the resulting matrix of matrix multiplication
// Function calculates the multiplication of first and second matrix, save that
// on the third matrix
void matrixMultiply(int **arrA, int **arrB, int **arrC, int a, int b, int c);

int main() {
    int i;
    int n, m, p;
    int **A, **B, **C;

    scanf("%d%d%d", &n, &m, &p);

    // Dynamically allocate memory for all 3 matrices
    A = (int **) malloc(sizeof(int *) * n);
    B = (int **) malloc(sizeof(int *) * m);
    C = (int **) malloc(sizeof(int *) * n);

    if(A == NULL || B == NULL || C == NULL) { // Check if all 3 were successful
        exit(1);
    }

    for(i = 0; i < n; i++) {
        A[i] = (int *) malloc(sizeof(int) * m);
        if(A[i] == NULL) { // Check if each array was successfully allocated
            exit(1);
        }
    }
    
    for(i = 0; i < m; i++) {
        B[i] = (int *) malloc(sizeof(int) * p);
        if(B[i] == NULL) { // Check if each array was successfully allocated
            exit(1);
        }
    }

    for(i = 0; i < n; i++) {
        C[i] = (int *) malloc(sizeof(int) * p);
        if(C[i] == NULL) { // Check if each array was successfully allocated
            exit(1);
        }
    }

    read(A, n, m);
    read(B, m, p);

    printf("Matrix A:\n");
    print(A, n, m);
    printf("Matrix B:\n");
    print(B, m, p);

    matrixMultiply(A, B, C, n, m, p);
    printf("The multiplication result AxB:\n");
    print(C, n, p);

    // Deallocate memory of A and C since they have same amount of 
    // pointers to arrays (rows)
    for(i = 0; i < n; i++) {
        free(A[i]);
        free(C[i]);
    }
    free(A);
    free(C);

    for(i = 0; i < m; i++)
        free(B[i]);
    free(B);

    return 0;
}

void read(int **arr, int a, int b) {
    int i, j;
    for(i = 0; i < a; i++) {
        for(j = 0; j < b; j++) {
            scanf("%d", &arr[i][j]);  // Input each element of the 2D-array
        }
    }
}

void print(int **arr, int a, int b) {
    int i, j;
    for(i = 0; i < a; i++) {
        for(j = 0; j < b; j++) {
            printf("%d ", arr[i][j]); // Print each element of the 2D-array
        }
        printf("\n"); // Print newline at end of 2D-array row
    }
}

void matrixMultiply(int **arrA, int **arrB, int **arrC, int a, int b, int c) {
    int i, j, k;
    for(i = 0; i < a; i++) { // Loop through rows of resulting matrix
        for(j = 0; j < c; j++) { // Loop through columns of resulting matrix
            arrC[i][j] = 0;
            // Calculate sum found in position [i,j] by looping through the 
            // elements of row i in first matrix and elements of column j in
            // second matrix and summing their respective product
            for(k = 0; k < b; k++) {
                arrC[i][j] = arrC[i][j] + (arrA[i][k] * arrB[k][j]);
            }
        }
    }
}