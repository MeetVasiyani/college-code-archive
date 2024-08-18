/*Copy all elements of one array to another.*/
#include <stdio.h>

void main() {
    int arr1[100], arr2[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements of the first array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }

    for (i = 0; i < n; i++) {
        arr2[i] = arr1[i];
    }

    printf("The elements of the second array are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }

}
