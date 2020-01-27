#include<stdio.h>
#include<ctype.h>

int main() {
	char c;
	
	scanf("%c", &c);
	
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) // Check if c is letter
		printf("%c is a letter\n", c);
	else if (c >= '0' && c <= '9') // Else check if it is a digit
		printf("%c is a digit\n", c);
	else 
		printf("%c is some other symbol\n", c); // Else it is a symbol
	
	return 0;
}