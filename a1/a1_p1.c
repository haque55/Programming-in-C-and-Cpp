#include<stdio.h>
int main() {
    double result; /* The result of our calculation */
    result = (3 + 1) / 5.0;
    /*
        Integer division produces an integer
		Division gives a number less than 1, it outputs 0 (it has to be integer)
        By changing one of the arguments to the division to double
        the output becomes a double automatically
    */
    printf("The value of 4/5 is %lf\n", result);
    return 0;
}