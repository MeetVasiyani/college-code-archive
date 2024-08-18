/* Estimate the value of the mathematical constant e. (Formula: 𝑒=1+1/1!+1/2!+1/3!+1/4!+...+1/n!)*/
#include <stdio.h>

int main() {
    int n, i;
    double e = 1.0;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        double factorial = 1.0;
        for (int j = 1; j <= i; j++) {
            factorial *= j;
        }
        e += 1.0 / factorial;
    }

    printf("The estimated value of e is: %.15f\n", e);

}
