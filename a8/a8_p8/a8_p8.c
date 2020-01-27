#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch;
    FILE *firstText, *secondText, *output;

    // Open text1.txt and text.2 to read
    firstText = fopen("text1.txt", "r"); 
    secondText = fopen("text2.txt", "r");

    // Create merge12.txt to store the merge between text1.txt and text2.txt
    output = fopen("merge12.txt", "w+");

    // Check if any fopen failed to open the file successfully
    if (firstText == NULL || secondText == NULL || output == NULL) {
        exit(1);
    } 

    // Read from text1.txt and write to merge12.txt
    while((ch = fgetc(firstText)) != EOF) {
        fputc((int) ch, output); 
    }
 
    // Read from text2.txt and write to merge12.txt
    while((ch = fgetc(secondText)) != EOF) {
        fputc((int) ch, output);
    }

    fclose(firstText);
    fclose(secondText);
    fclose(output);
    
    return 0; 
}