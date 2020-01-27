#include<stdio.h>
int main() {
    int result; /* The result of our calculation */
    result = (2 + 7) * 9 / 3;
    printf("The result is %d\n", result);
    /*
        The result is so random because we didn't give an argument to the
        printf function to substitute in place of %d, so it produces a random 
		value. By adding result as an argument to the function, we get the right
		value 27
    */
    return 0;
}