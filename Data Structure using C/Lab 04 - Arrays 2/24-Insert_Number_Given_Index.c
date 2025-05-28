/*24. Write a program to insert a number at a given location in an array. */
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
    int num, loc;
    printf("Enter number to be inserted : ");
    scanf("%d", &num);
    printf("Enter location : ");
    scanf("%d", &loc);
    int result[n + 1];

    for (int i = 0; i < loc - 1; i++) {
        result[i] = arr[i];
    }

    result[loc - 1] = num;

    for (int i = loc - 1; i < n; i++) {
        result[i + 1] = arr[i];
    }

    printf("Resultant array : ");
    for (int i = 0; i < n + 1; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}