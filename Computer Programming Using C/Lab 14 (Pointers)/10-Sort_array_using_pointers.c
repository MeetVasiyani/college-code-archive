/*Sort array using pointers.*/
#include <stdio.h>

void main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int *ptr;
    for (int i = 0; i < size - 1; i++) {
        ptr = arr + i;
        for (int j = i + 1; j < size; j++) {
            if (*ptr > *(arr + j)) {
                ptr = arr + j;
            }
        }
        int temp = *(arr + i);
        *(arr + i) = *ptr;
        *ptr = temp;
    }

    printf("Sorted array:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
