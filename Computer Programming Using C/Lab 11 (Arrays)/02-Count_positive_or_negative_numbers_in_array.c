/* Count number of positive or negative number from an array of n numbers.*/
#include <stdio.h>

void main() {
    int n, i, count_positive = 0, count_negative = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] > 0) {
            count_positive++;
        } else if (arr[i] < 0) {
            count_negative++;
        }
    }

    printf("Number of positive numbers: %d\n", count_positive);
    printf("Number of negative numbers: %d\n", count_negative);

}
