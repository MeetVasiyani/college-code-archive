/*Store n elements in an array and print the elements using pointer.*/
#include <stdio.h>
void main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *ptr = arr;

    printf("Elements of the array using pointers:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }

}
