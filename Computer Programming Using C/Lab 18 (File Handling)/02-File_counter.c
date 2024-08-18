/*Count chars, spaces, tabs and new lines in a file. */
#include <stdio.h>

int main() {
    FILE *fp;
    char filename[] = "abc.txt";
    char ch;
    int char_count = 0, space_count = 0, tab_count = 0, newline_count = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        char_count++;

        if (ch == ' ') {
            space_count++;
        } else if (ch == '\t') {
            tab_count++;
        } else if (ch == '\n') {
            newline_count++;
        }
    }

    fclose(fp);

    printf("Total characters: %d\n", char_count);
    printf("Total spaces: %d\n", space_count);
    printf("Total tabs: %d\n", tab_count);
    printf("Total new lines: %d\n", newline_count);

    return 0;
}
