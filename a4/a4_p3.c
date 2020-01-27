#include<stdio.h>
#include<math.h>

// Functions take an array and the size of the array as input and return a float
// value 
float geometric_mean(float arr[], int num);
float biggestNumber(float arr[], int num);
float smallestNumber(float arr[], int num);
float sumNumbers(float arr[], int num);

int main() {
    int i;
    char c;
    float arr[15], temp, geoMean, biggNum, smallNum, sum;

    // Loop to enter input
    for(i = 0; i < 15; i++) {
        scanf("%f", &temp);
        if(temp > 0) { // Check if input is > 0
            arr[i] = temp;
        } else {
            break; // Stop iterating if it is less than 0
        }
    }

    getchar();

    // Input the character that determines the function to be run
    scanf("%c", &c);

    // For each case, save the return value of the function and print it
    switch(c) {
        case 'm':
            geoMean = geometric_mean(arr, i);
            printf("%f\n", geoMean);
            break;
        case 'h' :
            biggNum = biggestNumber(arr, i);
            printf("%f\n", biggNum);
            break;
        case 'l' :
            smallNum = smallestNumber(arr, i);
            printf("%f\n", smallNum);
            break;
        case 's' :
            sum = sumNumbers(arr, i);
            printf("%f\n", sum);
            break;
    }

    return 0;
}

float geometric_mean(float arr[], int num) {
    int i;
    float mean = 1.0;
    for(i = 0; i < num; i++)
        // Calculate new product by multiplying with each element of arr 
        mean = mean * arr[i];
    return pow(mean, 1.0/(num)); // Raise to the power 1/n
}

float biggestNumber(float arr[], int num) {
    int i;
    float max = arr[0];
    for(i = 1; i < num; i++) {
        // Find max 
        if(arr[i] > max) { // If value at arr[i] is bigger than actual max
            max = arr[i]; // max is assigned the value of arr[i]
        }
    }
    return max;
}

float smallestNumber(float arr[], int num) {
    int i;
    float min = arr[0];
    for(i = 1; i < num; i++) {
        if(arr[i] < min) { // If value at arr[i] is less than actual max
            min = arr[i]; // max is assigned the value of arr[i]
        }
    }
    return min;
}

float sumNumbers(float arr[], int num) {
    int i;
    float sum = 0;
    for(i = 0; i < num; i++) // Run through each element of the array
        sum = sum + arr[i]; // Add them up to the sum
    return sum;
}