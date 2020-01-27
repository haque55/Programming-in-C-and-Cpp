#include<stdio.h>
#include<stdlib.h>

// Function returns an integer, takes an array of integers and an integer that
// its the size of the array. Function calculates the product of the smallest 
// and biggest integers in the array
int prodminmax(int arr[], int n);

int main() {
    int i, n, *arr, product;

    scanf("%d", &n);
    arr = (int *) malloc(sizeof(int) * n); 

    // Loop for accepting input
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    product = prodminmax(arr, n);
    printf("%d\n", product);

    return 0;
}

int prodminmax(int arr[], int n) {
    int i;
    int min = arr[0]; // min set to first element
    int max = arr[0]; // max set to first element

    for(i = 1; i < n; i++) {
        if(arr[i] > max) { // If value at arr[i] is bigger than actual max
            max = arr[i]; // max is assigned the value of arr[i]
        }
        if(arr[i] < min) { // If value at arr[i] is less than actual min
            min = arr[i]; // min is assigned the value of arr[i]
        }
    }

    return max * min; // return product of min and max
}