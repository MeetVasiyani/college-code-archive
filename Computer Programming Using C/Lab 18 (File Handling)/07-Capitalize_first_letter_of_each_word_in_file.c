/*Capitalize first letter of each word in file. */
#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[] = "abc.txt";
    char tempFilename[] = "temp.txt";
    int c;
    int newWord = 1;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    FILE *tempFile = fopen(tempFilename, "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(file);
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        if (newWord && isalpha(c)) {
            c = toupper(c);
            newWord = 0;
        }
        if (isspace(c)) {
            newWord = 1;
        }
        fputc(c, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename(tempFilename, filename);

    printf("First letter of each word capitalized in file %s.\n", filename);

    return 0;
}
