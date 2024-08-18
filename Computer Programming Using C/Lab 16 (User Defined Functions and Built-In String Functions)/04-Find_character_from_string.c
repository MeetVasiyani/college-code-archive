/*Find a character from given string.*/
#include <stdio.h>

void main() {
    char str[100];
    char target;
    int found = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter the character to find: ");
    scanf("%c", &target);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == target) {
            printf("Character '%c' found at index %d\n", target, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Character '%c' not found in the string\n", target);
    }

}
