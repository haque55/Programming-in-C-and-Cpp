#include <stdio.h>
 
int main() {
    char fst, snd;
    FILE *fileRead;
    fileRead = fopen("chars.txt", "r"); // Open input file
    if (fileRead) {
        // Read the first 2 characters of the file
        fst = getc(fileRead);
        snd = getc(fileRead);
    } else { // In case fopen was not successful
        printf("Couldn't open file...");
    }

    fclose(fileRead);

	FILE *fileWrite;
	fileWrite = fopen("codesum.txt", "w"); // Open output file
    // Write to the file an integer that is the sum of both int casted chars
	fprintf(fileWrite, "%d", (int) fst + (int) snd);
    
	fclose(fileWrite); 
	return 0;
}