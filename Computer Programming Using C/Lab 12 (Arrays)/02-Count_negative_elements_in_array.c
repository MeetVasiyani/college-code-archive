/*Count total number of negative elements in array. */
#include <stdio.h>

void main() {
    int arr[] = {-1, 2, -3, 4, -5, 6, -7, 8, -9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            count++;
        }
    }

    printf("Total number of negative elements in array: %d\n", count);

}
