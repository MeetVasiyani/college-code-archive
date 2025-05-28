/*95. Write a program to implement Merge Sort using Array.*/

#include <stdio.h>

void merge(int arr[],int start,int end,int mid){
    int temp[end - start + 1];
    int left = start, right = mid +1, index = 0;

    while(left <= mid && right <= end){
        if(arr[left] <= arr[right]){
            temp[index++] = arr[left++];
        }
        else{
            temp[index++] = arr[right++];
        }
    }

    while(left <= mid){
        temp[index++] = arr[left++];
    }

    while(right <= end){
        temp[index++] = arr[right++];
    }

    index = 0;
    while (start <= end) {
        arr[start++] = temp[index++];
    }

}

void mergeSort(int arr[],int start,int end){
    if(start >= end) return;
    int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end,mid);
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

    mergeSort(arr, 0, n-1);

    printf("Array after sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

}