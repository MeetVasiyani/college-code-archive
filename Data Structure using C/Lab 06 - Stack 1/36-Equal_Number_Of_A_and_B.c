/*36. Write a program to determine if an input character string is of the form aibi 
where i >= 1 i.e., Number of ‘a’ should be equal to number of ‘b’.*/

#include <stdio.h>
#include <string.h>

#define MAX 100

char stackA[MAX];
int topA = -1;

char stackB[MAX];
int topB = -1;

void pushA(char ch) {
    if (topA >= MAX - 1) {
        printf("Stack A Overflow\n");
        return;
    }
    stackA[++topA] = ch;
}

void pushB(char ch) {
    if (topB >= MAX - 1) {
        printf("Stack B Overflow\n");
        return;
    }
    stackB[++topB] = ch;
}

void main() {
    char str[MAX];
    int isValid = 1;

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a') {
            pushA(str[i]);
        } else if (str[i] == 'b') {
            pushB(str[i]);
        } else {
            isValid = 0;
            break;
        }
    }

    if (isValid) {
        if (topA == topB) {
            printf("There are equal number of 'a' and 'b'\n");
        } else {
            printf("There are not equal number of 'a' and 'b'\n");
        }
    } else {
        printf("You entered an invalid character. Enter only a/b\n");
    }

}
