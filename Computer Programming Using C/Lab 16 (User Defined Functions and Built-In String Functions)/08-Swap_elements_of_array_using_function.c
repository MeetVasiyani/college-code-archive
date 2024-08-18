/*Swap elements of two integer arrays using user define function.*/
#include <stdio.h>

void swapArrays(int arr1[], int arr2[], int size);

int main() {
    int size;
    
    // Input size of arrays
    printf("Enter the size of arrays: ");
    scanf("%d", &size);
    
    int arr1[size], arr2[size];
    
    // Input elements of first array
    printf("Enter elements of first array:\n");
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }
    
    // Input elements of second array
    printf("\nEnter elements of second array:\n");
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    printf("\nBefore swapping:\n");
    printf("Array 1: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nArray 2: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    swapArrays(arr1, arr2, size);

    printf("\nAfter swapping:\n");
    printf("Array 1: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nArray 2: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}

void swapArrays(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        int temp = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = temp;
    }
}
