/*97. Write a program to implement Counting Sort using Array. */

#include<stdio.h>

void countingSort(int arr[], int n, int max){
    int temp [max+1];
    int result [n];

    for (int i = 0; i < max + 1; i++) {
        temp[i] = 0;
    }

    for (int j = 0; j < n; j++) {
            temp[arr[j]]++;
    }

    for (int i = 1; i < max+1; i++) {
        temp[i] = temp[i] + temp[i-1];
    }

    for (int j = n-1; j >= 0; j--) {
        result[temp[arr[j]]-1] = arr[j];
        temp[arr[j]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = result[i];
    }
}

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: \n");
    for(int i=0; i<n; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    int max = arr[0];
    for (int i = 0; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    
    countingSort(arr,n,max);

    printf("Array after sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}