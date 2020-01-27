#include<stdio.h>

// Functions return nothing, take a 2-dimensional array of integers and an
// integer that is the number of rows and columns the array has
void printArr2D(int arr2D[30][30], int n); // Prints the array on the screen
void underMainDiag(int arr2D[30][30], int n); // Prints elements under main diag

int main() {
    int i, j, n, arr2D[30][30];

    scanf("%d", &n);

    // Loop for accepting input into the 2-D array
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &arr2D[i][j]);
        }
    }

    printArr2D(arr2D, n);
    underMainDiag(arr2D, n);

    return 0;
}

void printArr2D(int arr2D[30][30], int n) {
    int i, j;
    printf("The entered matrix is:\n");
    // Loop through the array and print each element
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", arr2D[i][j]);
        }
        printf("\n"); // Place a newline character at the end of the row
    }
}

void underMainDiag(int arr2D[30][30], int n) {
    int i, j;
    printf("Under the main diagonal:\n");
    // Loop through the array and print elements
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j < i) // Check if column index is less than row index
                printf("%d ", arr2D[i][j]);
        }
    }
    printf("\n");
}