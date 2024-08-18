/*Check for equality of two numbers without using arithmetic or comparison operator.*/
#include <stdio.h>

void main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    if ((num1 ^ num2) == 0) {
        printf("The two numbers are equal.\n");
    } 
    else {
        printf("The two numbers are not equal.\n");
    }

}
