/*. Print 1 to 10 then modify program print 1 to n*/
#include <stdio.h>

void main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Printing numbers from 1 to %d:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    printf("\n");
}