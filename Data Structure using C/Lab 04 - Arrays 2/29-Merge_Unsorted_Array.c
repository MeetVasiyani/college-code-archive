/*29. Write a program to merge two unsorted arrays.*/

#include <stdio.h>

void main(){
    int n1;
    printf("Enter length of 1st array: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter elements of 1st array in :\n");
    for (int i = 0; i < n1; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr1[i]);
    }

    int n2;
    printf("Enter length of 2nd array: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter elements of 2nd array in :\n");
    for (int i = 0; i < n2; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr2[i]);
    }

    int n3 = n1 + n2;
    int arr3[n3];

    for(int i = 0; i < n1; i++){
        arr3[i] = arr1[i];
    }
    for(int i = 0; i < n2; i++){
        arr3[i + n1] = arr2[i];
    }

    printf("Merged array: ");
    for(int i = 0; i < n3; i++){
        printf("%d ", arr3[i]);
    }
}