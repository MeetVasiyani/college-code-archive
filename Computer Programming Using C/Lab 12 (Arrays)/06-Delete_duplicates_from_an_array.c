/*Delete all duplicate elements from an array.Input from user*/
#include <stdio.h>

void main() {
    int n, i, j, k;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    k = 0;
    for (i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[k++] = arr[i];
        }
    }

    printf("Array without duplicates:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

}


