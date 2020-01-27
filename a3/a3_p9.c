#include<stdio.h>

double sum25(double v[], int n);

int main() {
    int n, i;
    double result;

    scanf("%d", &n);

    double arr[n];
    
    // Input elements
    for(i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    result = sum25(arr, n);

    if(result != -111.0) { // Print sum if we didn't get -111 as return value
        printf("sum=%lf\n", result);
    } else printf("One or both positions are invalid\n");

    return 0;
}

double sum25(double v[], int n) {
    if(n >= 6) { // If we have more than 5 elements, return sum of pos 2 and 5
        return v[2] + v[5];
    } else return -111;
}