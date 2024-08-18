/*Generate Fibonacci series of N given number using function name fibbo()*/
#include <stdio.h>

int main() {
    int n, i;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibbo(i));
    }
    return 0;
}

int fibbo(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibbo(n - 1) + fibbo(n - 2);
    }
}


