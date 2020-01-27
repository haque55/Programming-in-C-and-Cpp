#include<stdio.h>

// In order to pass the 2nd test case due to floating-point error
// I used doubles instead of floats for the 3rd and 4th argument

// Macro swap defined that takes 3 arguments
// It performs swap between 2nd and 3rd argument using a temporary variable
// Type of temporary variable is set by the first argument
#define swap(type, a, b) {type temp; temp = a; a = b; b = temp;}

int main() {
    int x, y;
    double w, z;
    scanf("%d%d%lf%lf", &x, &y, &w, &z);

    // Call macro with integers and call macro with double
    swap(int, x, y);
    swap(double, w, z);

    // Print result after swapping using macro swap
    printf("After swapping:\n%d\n%d\n%.6f\n%.6f\n", x, y, w, z);

    return 0;
}