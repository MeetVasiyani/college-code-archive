/*Calculate sum of two numbers using pointer.*/
#include <stdio.h>
void main() {
    int num1 = 10, num2 = 20;
    int sum;
    int *ptr1 = &num1;
    int *ptr2 = &num2;

    sum = *ptr1 + *ptr2;

    printf("Sum of %d and %d is: %d\n", *ptr1, *ptr2, sum);

}