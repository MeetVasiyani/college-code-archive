/*Replace a character in given string*/
#include <stdio.h>
#include <string.h>

void main() {
    char str[100];
    char replace, replacement;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the character to replace: ");
    scanf(" %c", &replace);

    printf("Enter the replacement character: ");
    scanf(" %c", &replacement);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == replace) {
            str[i] = replacement;
        }
    }

    printf("Modified string: %s\n", str);

}
