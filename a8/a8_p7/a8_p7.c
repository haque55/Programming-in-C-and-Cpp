#include <stdio.h>

int main () {
    FILE *firstFile, *secondFile, *output;
    double firstDouble, secondDouble;
    char firstFilename[32], secondFilename[32];

    printf("Enter first filename: ");
    scanf("%s*c", firstFilename);
    printf("Enter second filename: ");
    scanf("%s", secondFilename);

    // Open second file and read the double value inside
    firstFile = fopen(firstFilename, "r"); 
    if (firstFile == NULL) { // Check if opening file wasn't successful
        printf("Cannot open file %s \n", firstFilename); 
        return 0;
    } else {
        fscanf(firstFile, "%lf", &firstDouble);
    }

    fclose(firstFile);

    // Open second file and read the double value inside
    secondFile = fopen(secondFilename, "r"); 
    if (secondFile == NULL) { // Check if opening file wasn't successful
        printf("Cannot open file %s \n", secondFilename); 
        return 0;
    } else {
        fscanf(secondFile, "%lf", &secondDouble);
    }

    fclose(secondFile);

    // Print on file the result of different operations on both doubles
    output = fopen("results.txt", "w");
    fprintf(output, "Sum: %lf\n", firstDouble + secondDouble);
    fprintf(output, "Difference: %lf\n", firstDouble - secondDouble);
    fprintf(output, "Product: %lf\n", firstDouble * secondDouble);
    fprintf(output, "Division: %lf", firstDouble / secondDouble);

    fclose(output);

    return 0;
}