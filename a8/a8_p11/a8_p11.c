#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Integer to count number of successful writes to the output file
int countSuccessful = 0;

// Function returns nothing, takes 1 pointer to a char array and 1 FILE pointer
// File reads data from the file which name is the char array and writes it 
// to the FILE pointed at by argument pointer in binary mode using different
// chunk sizes depending on the amount of data being read
// It also prints the data being read into stdout
void transferData(char *fileName, FILE *output);

int main () {
    int n, i;
    char fileName[100];
    FILE *output = fopen("output.txt", "wb");

    if (output == NULL) // Check if opening output.txt was successful
        exit(1);

    scanf("%d", &n); // Input number of files being read
    getchar();

    printf("Concatenating the content of %d files ...\n", n);

    // For each file, read, write and print its data onto output and stdout
    for (i = 0; i < n; i++) {
        scanf("%s", fileName);
        transferData(fileName, output);
    }
    
    fclose(output);

    // Check if it successfully read and wrote each file
    if (countSuccessful == n)
        printf("The result was written into output.txt\n");
    
    return 0;
}

void transferData(char *fileName, FILE *output) {
    char buffer[64];
    memset(buffer, '\0', sizeof(buffer));

    FILE *file = fopen(fileName, "rb");

    if (file == NULL) // Check if opening file given was successful
        exit(1);

    // Find length of the file given
    fseek(file, 0L, SEEK_END);
    long length = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Read until length becomes 0 or fread returns 0
    while (fread(buffer, 1, length, file) && length > 0){
        int i;
        // Check if file length is less than 64 (buffer size)
        if (length < 64){
            // Print to stdout the values stored in buffer
            for(i = 0; i < length; i++)
                printf("%c", buffer[i]);
            printf("\n");
            // Set chunk size to match length and nmemb to 1
            fwrite(buffer, length, 1, output);
            length = 0;
        }
        else{
            // Print to stdout the values stored in buffer
            for(i = 0; i < length; i++)
                printf("%c", buffer[i]);
            printf("\n");
            // Set chunk size to 64 (buffer size) and nmemb to 1
            fwrite(buffer, 64, 1, output);
            // Decrease length by 64 as we have transferred 64 bytes
            length -= 64;
        }
    }

    fputc('\n', output); // Newline character after end of each file

    fclose(file);

    countSuccessful++;
}