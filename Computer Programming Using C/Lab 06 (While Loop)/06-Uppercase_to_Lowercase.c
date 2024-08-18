/*Print all uppercase and lowercase alphabets.*/
#include <stdio.h>
void main() {
    char c = 'A';
    printf("Uppercase characters:\n");
    while (c <= 'Z') {
        printf("%c ", c);
        c++;
    }
    c = 'a';
    printf("\nLowercase characters:\n");
    while (c <= 'z') {
        printf("%c ", c);
        c++;
    }
}
