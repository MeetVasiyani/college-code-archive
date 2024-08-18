/*Scan a character string passed as an argument and convert all lowercase string to uppercase string.*/
#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    char *str = argv[1];
    char *p = str;

    while (*p) {
        *p = toupper(*p);
        p++;
    }

    printf("Uppercase string: %s\n", str);

    return 0;
}
