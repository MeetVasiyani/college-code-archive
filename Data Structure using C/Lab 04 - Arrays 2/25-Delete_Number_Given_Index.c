/*25. Write a program to delete a number from a given location in an array.*/

#include <stdio.h>

void main() {
    int n;
    printf("Enter length of original array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of original array : \n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d : ", i + 1);
        scanf("%d", &arr[i]);
    }

    int loc;
    printf("Enter index to delete element : ");
    scanf("%d", &loc);

    if (loc >= 0 && loc < n) {
        for (int i = loc-1; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }

        printf("Resultant array : ");
        for (int i = 0; i < n - 1; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } 
    else {
        printf("Invalid index!\n");
    }
}