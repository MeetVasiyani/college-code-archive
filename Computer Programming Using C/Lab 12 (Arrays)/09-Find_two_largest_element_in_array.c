/*Find two largest elements in a one dimensional array.*/
#include <stdio.h>

int main() {
    int arr[100], n, i, j, max1, max2;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    max1 = max2 = arr[0];

    for (i = 1; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }

    printf("The two largest elements in the array are %d and %d\n", max1, max2);

    return 0;
}
