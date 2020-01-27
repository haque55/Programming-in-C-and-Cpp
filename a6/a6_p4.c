#include<stdio.h>
#include<stdlib.h>

// Function returns nothing, takes an integer n and 2 arrays of doubles
// n is the number of components of both arrays (vectors) v and w
// It calculates the scalar product of both vectors by finding the sum of the
// products of respective elements in v and w and outputs it to the screen
// In case INTERMEDIATE was defined as an argument to our build of the file
// function outputs also the intermediate value calculations
void scalarProduct(int n, double v[], double w[]) {
    int i;
    int scalProd = 0, temp = 0;
    // Iterate through both vectors and add product of respective positons to
    // scalProd (sum)
    // In case INTERMEDIATE is defined as argument in our build
    #if defined(INTERMEDIATE) 
        printf("The intermediate product values are:\n");
    #endif
    for(i = 0; i < n; i++) {
        temp = (v[i] * w[i]);
        scalProd += temp;
        // In case INTERMEDIATE is defined as argument in our build
        // output the intermediate values of scalar product
        #if defined(INTERMEDIATE)
            printf("%d\n", temp);
        #endif
    }
    printf("The scalar product is: %d\n", scalProd);
}

int main() {
    int n, i;
    double *v, *w;

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

    scalarProduct(n, v, w);

    free(v);
    free(w);

    return 0;
}