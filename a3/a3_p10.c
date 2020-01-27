#include<stdio.h>

float product(float a, float b);
void productbyref(float a, float b, float *p);
void modifybyref(float *a, float *b);

int main() {
    float num1, num2, prod;

    scanf("%f%f", &num1, &num2);
    // scanf("%f", &num2);

    productbyref(num1, num2, &prod);

    // Check if both functions peform the same calculation
    if(prod == product(num1, num2)) {
        printf("First and second function produce the same value: %f\n", prod);
    }

    // Show the effect that modifybyref() had on the input
    printf("First and second input before modifybyref: %f %f\n", num1, num2);
    modifybyref(&num1, &num2);
    printf("First and second input after modifybyref: %f %f\n", num1, num2);

    return 0;
}

float product(float a, float b) {
    return a * b;
}

void productbyref(float a, float b, float *p) {
    // Assign product to the address that pointer p is pointing to
    *p = a * b;
}

void modifybyref(float *a, float *b) {
    // Dereference each pointer and add 3 and 11 respectively to them
    *a = *a + 3;
    *b = *b + 11;
}