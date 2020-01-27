#include<stdio.h>

void sumTemp(double *arr, int size);
void listTempsCelsius(double *arr, int size);
void listTempsFahrenheit(double *arr, int size);
void averageTemps(double *arr, int size);

int main() {
    char c;
    int n, i;

    scanf("%c", &c);
    getchar();

    scanf("%d", &n);
    getchar();

    double tempsCelsius[n];

    // Input temperatures inside of the array one by one
    for(i = 0; i < n; i++) {
        scanf("%lf", &tempsCelsius[i]);
    }

    switch (c) {
        case 's':
            sumTemp(tempsCelsius, n);
            break;
        case 'p':
            listTempsCelsius(tempsCelsius, n);
            break;
        case 't':
            listTempsFahrenheit(tempsCelsius, n);
            break;
        default:
            averageTemps(tempsCelsius, n);
            break;
    }
    return 0;
}

void sumTemp(double *arr, int size) {
    int i;
    double sum;
    // Iterate through each element of the array and add them up to sum
    for(i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    printf("%lf\n", sum);
}

void listTempsCelsius(double *arr, int size) {
    int i;
    // Print each element of the array
    for(i = 0; i < size; i++) {
        printf("%lf\n", *(arr + i));
    }
}

void listTempsFahrenheit(double *arr, int size) {
    int i;
    double fahrenheit;
    for(i = 0; i < size; i++) {
        // Convert from celsius to fahrenheit each element we iterate through
        fahrenheit = (9 / 5.0) * (*(arr + i)) + 32;
        printf("%lf\n", fahrenheit);
    }
}

void averageTemps(double *arr, int size) {
    int i;
    double average, sum;
    // Iterate through each element of the array and add them up to sum
    for(i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    average = sum / size;
    printf("%lf\n", average);
}