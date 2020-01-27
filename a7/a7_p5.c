#include <stdio.h>
#include <stdlib.h>

// Function returns an int and takes 2 void pointers
// Function comparator to sort ascending using the difference between
// the first and second element
int compareAscend(const void *a, const void *b);

// Function returns an int and takes 2 void pointers
// Function comparator to sort descending using the difference between
// the second and first element
int compareDescend(const void *a, const void *b);

// Function returns nothing, it takes a pointer to a char array and an int
// that is the size of the array
// It prints the elements of the array one by one
void print(int *arr, int size);

int main() {
    int n, *arr;
    char ch;

    int i;
    scanf("%d", &n);
    arr = (int *) malloc(sizeof(int) * n);

    if(arr == NULL) { // Check if malloc was successful
        exit(1);
    }

    // Loop for accepting input
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    getchar();

    while(1) {
        scanf("%c", &ch);
        getchar();
        if(ch == 'a') {
            qsort(arr, n, sizeof(int), compareAscend);
            print(arr, n);
        } else if (ch == 'd') {
            qsort(arr, n, sizeof(int), compareDescend);
            print(arr, n);
        } else if (ch == 'e') {
            free(arr);
            return 0;
        }
    }
    
    free(arr);
    return 0;
}

int compareAscend(const void *a, const void *b) {
    // Casts both void pointers to int pointers and dereferences to find the
    // difference between first and second
    return (*(int*)a - *(int*)b);
}

int compareDescend(const void *a, const void *b) {
    // Casts both void pointers to int pointers and dereferences to find the
    // difference between second and first
    return (*(int *)b - *(int *)a);
}

void print(int *arr, int size) {
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}