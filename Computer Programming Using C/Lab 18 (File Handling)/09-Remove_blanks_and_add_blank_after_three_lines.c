/*Capitalize the first letter of every word in a file.*/
#include <stdio.h>

int main() {
    FILE *file, *tempFile;
    char filename[] = "abc.txt";
    char tempFilename[] = "temp.txt";
    char line[1000];
    int lineCount = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] != '\n') {
            lineCount++;
            fputs(line, tempFile);
            if (lineCount == 3) {
                fprintf(tempFile, "\n");
            }
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename(tempFilename, filename);

    printf("Blank lines deleted and a blank line inserted after the third line in file %s.\n", filename);

    return 0;
}
