/*Find all prime numbers between given interval using functions.*/
#include <stdio.h>

void find_primes_in_interval(int start, int end) {
    int i, j, is_prime;

    printf("Prime numbers between %d and %d are:\n", start, end);
    for (i = start; i <= end; i++) {
        if (i <= 1) {
        continue;
    }

        is_prime = 1;

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int start, end;

    printf("Enter the start of the interval: ");
    scanf("%d", &start);
    printf("Enter the end of the interval: ");
    scanf("%d", &end);

    find_primes_in_interval(start, end);

    return 0;
}

