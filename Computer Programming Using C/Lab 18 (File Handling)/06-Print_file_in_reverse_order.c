/*Print contents of file in reverse order.*/
#include <stdio.h>

#define MAX_SIZE 10000 // Maximum file size assumed

int main() {
    FILE *file;
    char filename[] = "abc.txt";
    char buffer[MAX_SIZE];
    long file_size, i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    if (file_size <= 0) {
        printf("Empty file!\n");
        fclose(file);
        return 1;
    }

    if (file_size >= MAX_SIZE) {
        printf("File size exceeds maximum buffer size!\n");
        fclose(file);
        return 1;
    }

    fread(buffer, sizeof(char), file_size, file);

    fclose(file);

    printf("Contents of %s in reverse order:\n", filename);
    for (i = file_size - 1; i >= 0; i--) {
        printf("%c", buffer[i]);
    }

    return 0;
}
