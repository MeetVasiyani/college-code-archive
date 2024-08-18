/*Print multiplication table of a given number.*/
#include <stdio.h>

void main() {
    int num, count = 1;

    printf("Enter a number:");
    scanf("%d",&num);

    printf("\nMultiplication table for %d is:\n\n", num);

    while (count <= 10) {
        printf("%d x %d = %d\n", num, count, (num * count));
        count++;
    }
}