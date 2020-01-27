#include<stdio.h>

// Pass array address, last position of the input iterator and address of sum
void sumNums(float *values, int lastNumberPos, float *sum);
void averageNums(float *values, int lastNumberPos, float *sum, float *average);

int main() {
    int i;
    float values[10];
    float temp = 0, sum = 0, average = 0;

    // Loop to enter input
    for(i = 0; i < 10; i++) {
        scanf("%f", &temp);
        if(temp != -99.0) { // Check if input is -99
            values[i] = temp;
        } else {
            break; // Stop iterating if it is -99
        }
    }

    // Check in case we didn't get any element before -99
    if(i != 0) {
        sumNums(values, i, &sum);
        averageNums(values, i, &sum, &average);
    }

    printf("%f\n", sum);
    printf("%f\n", average);

    return 0;
}

void sumNums(float *values, int lastNumberPos, float *sum) {
    int i;
    for(i = 0; i <= lastNumberPos; i++) {
        // Add each element, from 0 to lastNumberPos, to sum
        *sum = *sum + (*(values + i));
    }
}

void averageNums(float *values, int lastNumberPos, float *sum, float *average) {
    *average = *sum / lastNumberPos;
}