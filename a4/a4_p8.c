#include<stdio.h>

// Functions return nothing, take a 2-dimensional array of integers and an
// integer that is the number of rows and columns the array has
void printArr2D(int arr2D[30][30], int n); // Prints the array on the screen
void underSecondDiag(int arr2D[30][30], int n); // Prints element under 2nd diag

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
    underSecondDiag(arr2D, n);

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

void underSecondDiag(int arr2D[30][30], int n) {
    int i, j;
    printf("Under the secondary diagonal:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            // Check if column index is smaller than n - row index - 1 in order
            // to print the elements on the right(down) side of the 2nd diag
            if(j > (n-i-1))
                printf("%d ", arr2D[i][j]);
        }
    }
    printf("\n");
}