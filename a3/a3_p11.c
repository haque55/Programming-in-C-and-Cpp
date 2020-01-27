#include<stdio.h>
#include<string.h>

int main() {
    char one[100], two[100], three[100];

    scanf("%[^\n]%*c", one);
    scanf("%[^\n]s*c", two);
    getchar();

    int compareResult = strcmp(one, two); // Compare strings before concat

    // Print length of one and two
    printf("length1=%d\nlength2=%d\n", (int) strlen(one), (int) strlen(two));

    strcat(one, two);
    printf("concatenation=%s\n", one);

    strcpy(three, two);
    printf("copy=%s\n", three);

    // Print different output varying from the return value of strcmp
    if(compareResult < 0){
        printf("one is smaller than two\n");
    } else if (compareResult > 0) {
        printf("one is larger than two\n");
    } else printf("one is equal to two\n");

    char c;
    char *ptr_a;
    scanf("%c", &c);
    ptr_a = strchr(two, c);
    
    if(ptr_a == NULL) { // If we didn't find any occurence of c in two
        printf("The character is not in the string\n");
    } else printf("position=%d\n", (int) (ptr_a - two)); // Else print position

    return 0;
}