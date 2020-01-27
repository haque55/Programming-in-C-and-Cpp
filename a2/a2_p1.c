#include<stdio.h>

int main() {
	double a, b;
	int c, d;
	char e, f;
	
	// Input doubles, integers and characters
	scanf("%lf", &a);
	getchar();
	scanf("%lf", &b);
	getchar();
	scanf("%d", &c);
	getchar();
	scanf("%d", &d);
	getchar();
	scanf("%c", &e);
	getchar();
	scanf("%c", &f);
	getchar();

	printf("sum of doubles=%lf\n", a + b);
	printf("difference of doubles=%lf\n", a - b);
	printf("square=%lf\n", a * a);
	printf("sum of integers=%d\n", c + d);
	printf("product of integers=%d\n", c * d);
	printf("sum of chars=%d\n", e + f);
	printf("product of chars=%d\n", e * f);
	printf("sum of chars=%c\n", (char) (e + f)); // Cast as char after sum
	printf("product of chars=%c\n", (char) (e * f)); // Cast as char after *

	return 0;	
}