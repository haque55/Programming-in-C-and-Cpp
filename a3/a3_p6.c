#include<stdio.h>

// Implementation of conversion from kg and g to pounds
float to_pounds(int kg, int g) {
    float pounds;
    pounds = (kg * 2.2) + (g * 0.0022);
    return pounds;
}

int main() {
    int kg, g;
    float pounds;

    scanf("%d", &kg);
    getchar();
    scanf("%d", &g);

    // Assign return value of to_pounds() to float variable pounds
    pounds = to_pounds(kg, g);

    printf("Result of conversion: %f\n", pounds);
    
    return 0;
}