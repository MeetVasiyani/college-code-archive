/*Calculate the sum of n numbers entered by the user using malloc(). */
#include <stdio.h>
#include <stdlib.h>

void main() {
    int n, *arr, sum = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    printf("Sum of the %d numbers = %d\n", n, sum);

    free(arr);

}
