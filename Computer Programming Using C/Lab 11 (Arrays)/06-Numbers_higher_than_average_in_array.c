/*Count numbers higher than the average of an array. */
#include <stdio.h>

void main() {
    int n, i, sum = 0, count = 0;
    float avg;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    avg = (float)sum / n;

    printf("Numbers higher than the average:\n");
    for (i = 0; i < n; i++) {
        if (arr[i] > avg) {
            printf("%d ", arr[i]);
            count++;
        }
    }

    printf("\nTotal numbers higher than the average: %d\n", count);

}
