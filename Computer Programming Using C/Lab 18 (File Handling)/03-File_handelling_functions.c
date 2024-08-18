/*Demonstrate functions fprintf(), fscanf(), fputc(), fgetc(), fseek() and rewind(). */
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[] = "abc.txt";
    int number = 123;
    char str[50];

    // Writing to a file using fprintf()
    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "%d %s", number, "Hello, world!");
    fclose(fp);

    // Reading from a file using fscanf()
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fscanf(fp, "%d %s", &number, str);
    printf("Read from file: %d %s\n", number, str);
    fclose(fp);

    // Appending to a file using fprintf()
    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(fp, "\nThis is appended content.");
    fclose(fp);

    // Reading character by character using fgetc()
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    printf("Contents of the file:\n");
    int c;
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);

    // Using fseek() to move the file pointer
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fseek(fp, 6, SEEK_SET); // Move to the 6th byte from the beginning of the file
    printf("\nAfter fseek(), content from 6th byte: ");
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);

    // Using rewind() to move the file pointer to the beginning
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    rewind(fp);
    printf("\nAfter rewind(), content from the beginning: ");
    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }
    fclose(fp);

    return 0;
}
