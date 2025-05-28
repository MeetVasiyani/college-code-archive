/*38. You are given a string s, which contains stars *. In one operation, you can: 
Choose a star in s. Remove the closest non-star character to its left, as well as 
remove the star itself. Return the string after all stars have been removed. 
Sample Example-1: 
Input: s = "leet**cod*e".             
Output: "lecoe" 
 
Sample Example-2: 
Input: s = "erase*****"     
Output: "" 
*/

#include <stdio.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char ch) {
    if (top == MAX_SIZE - 1) {
        return;
    }
    stack[++top] = ch;
}

char pop() {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

void main() {
    char str[MAX_SIZE];
    char res[MAX_SIZE];
    int resIndex = 0;

    printf("Enter a star-studded string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '*') {
            pop();
        } else {
            push(str[i]);
        }
    }

    for (int i = 0; i <= top; i++) {
        res[resIndex++] = stack[i];
    }
    res[resIndex] = '\0';

    printf("Resulting string: %s\n", res);

}
