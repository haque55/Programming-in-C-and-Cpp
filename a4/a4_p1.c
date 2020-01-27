#include<stdio.h>
#include<math.h>

int main() {
    float lower, upper, step;

    scanf("%f", &lower);
    scanf("%f", &upper);
    scanf("%f", &step);

    // Iterate from lower to upper value by adding the step each time to lower
    for(; lower <= upper; lower = lower + step) {
        // Calculate perimeter and area using pre-defined constant M_PI
        printf("%f %f %f\n", lower,  lower * lower * M_PI, M_PI * 2.0 * lower);
    }
    
    return 0;
}