#include<stdio.h>

int main() {
	char ch;
	int n, i;
	
	scanf("%c", &ch);
	getchar();
	scanf("%d", &n);
	
	// Print all the corresponding characters with ASCII value from ch to ch-n
	for(i = 0; i <= n; i++) {
		printf("%c\n", (char) ch - i);
	}
	
	return 0;
}