#include<stdio.h>

// Macro MIN taking 4 arguments
// Find smallest out of the first three and assign that value to the fourth
#define MIN(a, b, c, min) { \
    if((a <= b) && (a <= c)) \
        {min = a;} \
    else if((b <= a) && (b <= c)) \
        {min = b;} \
    else min = c; \
}

// Macro MAX taking 4 arguments
// Find biggest out of the first three and assign that value to the fourth
#define MAX(a, b, c, max) { \
    if((a >= b) && (a >= c)) \
        {max = a;} \
    else if((b >= a) && (b >= c)) \
        {max = b;} \
    else max = c; \
}

// Maco MID_RANGE taking 3 arguments
// Find mid from the sum of maximum and minimum of the 3 values before
// and divide that by 2 to get middle value (mid range) 
#define MID_RANGE(max, min, mid) { \
    mid = (min + max) / 2.0; \
}

int main() {
    int a, b, c, min, max;
    float mid;

    scanf("%d%d%d", &a, &b, &c);

    // Find min and max through macros MIN and MAX
    MIN(a, b, c, min);
    MAX(a, b, c, max);

    // Find middle value by using the calculated min and max from other macros
    MID_RANGE(max, min, mid);

    printf("The mid-range is: %f\n", mid);

    return 0;
}