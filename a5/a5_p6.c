#include<stdio.h>
#include<stdlib.h>

// Function returns nothing, it takes an integer and a pointer to an array of 
// floats (integer is used for recursivity)
// It counts the number of non-negative values before the first negative element
void countPosBeforeNeg(int count, float *ptr_arr);

int main() {
    int i, size, count = 0;
    float *dynArr;

    scanf("%d", &size);

    dynArr = (float *) malloc(sizeof(float) * size);

    if(dynArr == NULL) {
        exit(1);
    }

    // Loop for accepting input
    for(i = 0; i < size; i++) {
        scanf("%f", &dynArr[i]);
    }

    countPosBeforeNeg(count, dynArr);

    free(dynArr);

    return 0;
}

void countPosBeforeNeg(int count, float *ptr_arr) {
    if((*(ptr_arr + count))< 0) { // Check if element is negative
        printf("Before the first negative value: %d elements", count);
    } else { // Increment count since we didn't encounter a negative element
        count++;
        // Recursive call to check next element
        countPosBeforeNeg(count, ptr_arr);
    }
}