/*Append one file at the end of other.*/
#include <stdio.h>

int main() {
    FILE *sourceFile, *destinationFile;
    char sourceFilename[] = "abc.txt";
    char destinationFilename[] = "xyz.txt";
    int c;

    sourceFile = fopen(sourceFilename, "r");
    if (sourceFile == NULL) {
        printf("Error opening source file!\n");
        return 1;
    }

    destinationFile = fopen(destinationFilename, "a");
    if (destinationFile == NULL) {
        printf("Error opening destination file!\n");
        fclose(sourceFile);
        return 1;
    }

    while ((c = fgetc(sourceFile)) != EOF) {
        fputc(c, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("Contents of %s appended to %s successfully.\n", sourceFilename, destinationFilename);

    return 0;
}
