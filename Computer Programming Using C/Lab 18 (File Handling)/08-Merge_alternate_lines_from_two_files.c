/*Merge alternate lines from two files.*/
#include <stdio.h>

int main() {
    FILE *file1, *file2, *outputFile;
    char filename1[] = "abc.txt";
    char filename2[] = "xyz.txt";
    char outputFilename[] = "merged.txt";
    char line[100];

    file1 = fopen(filename1, "r");
    if (file1 == NULL) {
        printf("Error opening file %s!\n", filename1);
        return 1;
    }

    file2 = fopen(filename2, "r");
    if (file2 == NULL) {
        printf("Error opening file %s!\n", filename2);
        fclose(file1);
        return 1;
    }

    outputFile = fopen(outputFilename, "w");
    if (outputFile == NULL) {
        printf("Error opening file %s for writing!\n", outputFilename);
        fclose(file1);
        fclose(file2);
        return 1;
    }

    while (fgets(line, sizeof(line), file1) != NULL && fgets(line, sizeof(line), file2) != NULL) {
        fputs(line, outputFile);
        fputs(line, outputFile);
    }

    while (fgets(line, sizeof(line), file1) != NULL) {
        fputs(line, outputFile);
    }
    while (fgets(line, sizeof(line), file2) != NULL) {
        fputs(line, outputFile);
    }

    fclose(file1);
    fclose(file2);
    fclose(outputFile);

    printf("Alternate lines from %s and %s merged into %s.\n", filename1, filename2, outputFilename);

    return 0;
}
