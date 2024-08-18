/* Input a string in character array and print string and length of string.Do not use string library function.*/
#include <stdio.h>

void main() {
    char str[100];
    int i, len = 0;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        len++;
    }

    printf("String: %s\n", str);
    printf("Length of string: %d\n", len);

}

