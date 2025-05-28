/*28. Write a program to delete duplicate numbers from an array. */

#include <stdio.h>

void main(){
    int n;
    printf("Enter length of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array :\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    //Sort the array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    //Remove duplicates
    int unique[n];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            unique[j++] = arr[i];
        }
    }

    n = j;
    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", unique[i]);
    }

}