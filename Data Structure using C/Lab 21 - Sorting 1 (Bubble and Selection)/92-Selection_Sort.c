/*92. Write a program to implement Selection Sort using Array.*/

#include <stdio.h>

void main(){
    int n;
    printf("Enter length of the input array : ");
    scanf("%d",&n);

    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    printf("Input array : ");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    printf("Sorted array : ");
    for(int i = 0; i < n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}