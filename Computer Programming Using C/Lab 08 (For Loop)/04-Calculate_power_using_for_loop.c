/*Calculate 𝑥𝑦 without using power function. */
#include <stdio.h>

void main() {
    int x, y;
    long long result = 1; // Using long long to handle large results
    printf("Enter the value of x and y: ");
    scanf("%d %d", &x, &y);
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    printf("%d raised to the power %d is: %lld\n", x, y, result);
}
