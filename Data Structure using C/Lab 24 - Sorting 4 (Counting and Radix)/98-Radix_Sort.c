/*98. Write a program to implement Radix Sort using Array. */

#include <stdio.h>

void radixSort(int arr[], int n, int pos){
    int temp[10] = {0};
    int result[n];

    for(int j = 0; j < n; j++){
        temp[(arr[j]/pos)%10]++;
    }

    for(int i = 1; i < 10; i++){
        temp[i] = temp[i] + temp[i-1];
    }

    for(int j = n-1; j >=0; j--){
        result[temp[(arr[j]/pos)%10]-1] = arr[j];
        temp[(arr[j]/pos)%10]--;
    }

    for(int j = 0; j < n; j++){
        arr[j] = result[j];
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

    for(int pos = 1; max/pos > 0; pos *= 10){
        radixSort(arr, n, pos);
    }

    printf("Array after sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}