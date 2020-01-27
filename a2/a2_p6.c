#include<stdio.h>

int main() {
	double x, y;
	
	// Initiliazing pointers to x and y
	double* ptr_one = &x;
	double* ptr_two = &x;
	double* ptr_three = &y;
	
	// Printing statements
	printf("Pointer ptr_one contains memory address: %p\n", ptr_one);
	printf("Pointer ptr_two contains memory address: %p\n", ptr_two);
	printf("Pointer ptr_three contains memory address: %p\n", ptr_three);	
	
	// Check if first two are same and the third one is different
	if(ptr_one == ptr_two)
		printf("Pointer ptr_one and pointer ptr_two point to same address.\n");
	if((ptr_one != ptr_three) && (ptr_two != ptr_three))
		printf("Pointer ptr_three is different from ptr_one and ptr_two.\n");
		
	return 0;
}