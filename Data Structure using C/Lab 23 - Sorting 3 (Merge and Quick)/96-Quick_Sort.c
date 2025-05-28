/*96. Write a program to implement Quick Sort using Array.*/

#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high-1){
            i++;
        }
        while(arr[j] > pivot && j >= low+1){
            j--;
        }
        if (i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}

void quickSort(int arr[],int low,int high){
    if(low < high){
        int pivot = partition(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
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

    quickSort(arr,0,n-1);

    printf("Array after sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}