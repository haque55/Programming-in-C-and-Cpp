#include<stdio.h>
int main () {
    int x = 17;
    int y = 4;
    
    printf("x=%d\n", x);
    printf("y=%d\n", y);
    printf("sum=%d\n", x+y);
    printf("product=%d\n", x*y);
    printf("difference=%d\n", x-y);
    printf("division=%f\n", (float)x / y);
    printf("remainder of division=%d\n", x%y);
    
    return 0;
}