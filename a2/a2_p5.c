#include<stdio.h>

int main() {
	int a;
	int* ptr_a = &a;
	
	scanf("%d", &a);
	
	// Print the address that ptr_a has stored
	printf("%p\n", ptr_a);
	
	// Increment the value that ptr_a is pointing to by 5 
	*ptr_a = *ptr_a + 5;
	
	// Print the value by dereferencing ptr_a
	printf("%d\n", *ptr_a);
	printf("%p\n", ptr_a);
	
	return 0;
}