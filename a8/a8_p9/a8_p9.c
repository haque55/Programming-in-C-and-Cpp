#include <stdio.h>
#include <ctype.h>

int main() {
    int continuousFlag = 0, count = 0;
    char ch, fileName[100];
    FILE *file;

    scanf("%s", fileName);

    file = fopen(fileName, "r");

    /*
        Checks word count, taking as granted that the text file only contains
        alphabet and separating letters given in assignment description
    */
    while ((ch = (fgetc(file))) != EOF) {
        // Check if character is an alphabet letter
        if(isalpha(ch)) {
            continuousFlag = 1; // Continuous flag set to 1 to mark word
            continue; // Go onto next character
        } else { // ELse the character is a separator
            if(continuousFlag == 1) { // If last character was alpha
                continuousFlag = 0; // Flag set to 0 to mark separator
                count++;
            } else continue;
            // If last char was not alpha that means we have separators in row
        }
    }

    fclose(file);

    // Print different output depending on word count
    if (count == 0)
        printf("The file contains no words.\n");
    else if (count == 1)
        printf("The file contains 1 word.\n");
    else printf("The file contains %d words.", count);

    return 0;
}