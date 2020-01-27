#include<stdio.h>
#include<string.h>
#include<stdbool.h> 

int main() {
    int position = 0;
    bool hasOccured = false;
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
    char *ptr;
    scanf("%c", &c);

    ptr = strchr(two, c);
    
    while(ptr != NULL) { // Check if our character doesn't appear at all
        // Position casted as int of difference between address of ptr and two
        position = (int) (ptr - two);
        printf("position=%d\n", position);
        ptr = strchr(&(two[position+1]), c); // Check rest of string
        hasOccured = true; // Change boolean value to true if character occured
    }
    if(hasOccured == false) { // Output if hasOccured never changed
        printf("The character is not in the string\n");
    }

    return 0;
}