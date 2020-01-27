#include<stdio.h>
#include<stdlib.h>

// Function returns a double value, takes an integer n and 2 arrays of doubles
// n is the number of components of both arrays (vectors) v and w
// It calculates the scalar product of both vectors by finding the sum of the
// products of respective elements in v and w
double scalarProduct(int n, double v[], double w[]);

// Function returns nothing, takes an integer n and one array of doubles
// smallestV finds the smallest value and its position in the array
void smallestV(int n, double v[]);

// Function returns nothing, takes an integer n and one array of doubles
// largestV finds the greatest value and its position in the array
void largestV(int n, double v[]);

int main() {
    int n, i;
    double *v, *w;
    double product;

    scanf("%d", &n);

    // Allocate memory for both vectors
    v = (double *) malloc(sizeof(double) * n);
    w = (double *) malloc(sizeof(double) * n);

    if((v == NULL) || (w == NULL)) { // Check if malloc was successful on both
        exit(1);
    }

    // Loop for accepting input into array v
    for(i = 0; i < n; i++) {
        scanf("%lf", &v[i]);
    }

    // Loop for accepting input into array w
    for(i = 0; i < n; i++) {
        scanf("%lf", &w[i]);
    }

    product = scalarProduct(n, v, w);
    printf("Scalar product=%lf\n", product);

    smallestV(n, v);
    largestV(n, v);
    smallestV(n , w);
    largestV(n, w);

    free(v);
    free(w);

    return 0;
}

double scalarProduct(int n, double v[], double w[]) {
    int i;
    double scalProd = 0;
    // Iterate through both vectors and add product of respective positons to
    // scalProd (sum)
    for(i = 0; i < n; i++) {
        scalProd = scalProd + (v[i] * w[i]);
    }
    return scalProd;
}

void smallestV(int n, double v[]) {
    int i, pos = 0;
    float min = v[0]; // min set to first element
    for(i = 1; i < n; i++) {
        // Find min
        if(v[i] < min) { // If value at v[i] is less than actual min
            min = v[i]; // min is assigned the value of v[i]
            pos = i; // position of smallest is assigned the value of i
        }
    }
    printf("The smallest = %lf\n", min);
    printf("Position of smallest = %d\n", pos);
}

void largestV(int n, double v[]) {
    int i, pos = 0;
    float max = v[0]; // max set to first element
    for(i = 1; i < n; i++) {
        // Find max
        if(v[i] > max) { // If value at v[i] is bigger than actual max
            max = v[i]; // max is assigned the value of v[i]
            pos = i; // position of biggest is assigned the value of i
        }
    }
    printf("The largest = %lf\n", max);
    printf("Position of largest = %d\n", pos);
}