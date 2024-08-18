/*Calculate the average, geometric and harmonic mean of n elements in an array.*/

#include <stdio.h>

void main() {
    int n, i;
    float sum = 0, product = 1, harmonic_sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
        sum += arr[i];
        product *= arr[i];
        harmonic_sum += 1.0 / arr[i];
    }

    float average = sum / n;
    float geometric_mean = pow(product, 1.0 / n);
    float harmonic_mean = n / harmonic_sum;

    printf("Average: %.2f\n", average);
    printf("Geometric mean: %.2f\n", geometric_mean);
    printf("Harmonic mean: %.2f\n", harmonic_mean);

}
