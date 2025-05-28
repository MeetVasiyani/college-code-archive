/*16. Write a program to read and display n numbers using an array. */
#include <stdio.h>

void main(){
    int n;
    printf("Enter length of the array : ");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Array Elements are : [ "); 
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");
}