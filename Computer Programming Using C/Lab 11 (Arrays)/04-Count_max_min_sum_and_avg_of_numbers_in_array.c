/* Find Max, Min, Sum, Avg. of given numbers from an array.*/
#include <stdio.h>

void main() {
    int n, i, max, min, sum = 0;
    float avg;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max = arr[0];
    min = arr[0];
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        sum += arr[i];
    }

    avg = (float)sum / n;

    printf("Maximum number: %d\n", max);
    printf("Minimum number: %d\n", min);
    printf("Sum of numbers: %d\n", sum);
    printf("Average of numbers: %.2f\n", avg);
}
