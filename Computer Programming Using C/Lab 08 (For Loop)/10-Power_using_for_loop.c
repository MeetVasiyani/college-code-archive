/*Calculate 𝑥𝑦 without using power function and without using multiplication. */
#include <stdio.h>

void main() {
    int x, y;
    long long result = 1;
    printf("Enter the value of x and y: ");
    scanf("%d %d", &x, &y);
    if (y < 0) {
        x = 1 / x;
        y = -y;
    }
    for (int i = 0; i < y; i++) {
        result *= x;
    }

    printf("%d raised to the power %d is: %lld\n", x, y, result);
}
