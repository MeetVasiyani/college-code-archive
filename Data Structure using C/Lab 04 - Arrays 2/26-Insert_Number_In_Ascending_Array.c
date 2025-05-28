/*26. Write a program to insert a number in an array that is already sorted in an 
ascending order. */

#include <stdio.h>

void main() {
    int n;
    printf("Enter length of original array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of original array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int num;
    printf("Enter number to be inserted: ");
    scanf("%d", &num);

    int result[n + 1];
    int inserted = 0, i, j;

    for (i = 0, j = 0; i < n; i++, j++) {
        if (!inserted && num < arr[i]) {
            result[j++] = num;
            inserted = 1;
        }
        result[j] = arr[i];
    }

    if (!inserted) {
        result[j] = num;
    }

    printf("Array after insertion: ");
    for (int i = 0; i <= n; i++) {
        printf("%d ", result[i]);
    }

}
