/*Convert decimal number to binary. (i.e. n=11  output: 1101)*/
#include <stdio.h>
void main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);

    int binary = 0, remainder, temp = 1;

    while (n != 0) {
        remainder = n % 2;
        n /= 2;
        binary += remainder * temp;
        temp *= 10;
    }

    printf("Binary representation: %d\n", binary);
}
