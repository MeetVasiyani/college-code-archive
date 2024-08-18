/*C Program find nCr (Combination) and nPr (Permutation). (Formula: nCr = n!/(r!*(n-r)!), nPr = n!/(n-r)!)*/
#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n, r;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of r: ");
    scanf("%d", &r);

    int nCr = factorial(n) / (factorial(r) * factorial(n - r));
    int nPr = factorial(n) / factorial(n - r);

    printf("nCr = %d\n", nCr);
    printf("nPr = %d\n", nPr);

    return 0;
}
