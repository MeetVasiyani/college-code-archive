/*Print multiplication table of a given number.*/
#include <stdio.h>

void main() {
    int n;
    printf("Enter the number for which you want to print the multiplication table: ");
    scanf("%d", &n);
    printf("Multiplication table of %d:\n", n);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }
}
