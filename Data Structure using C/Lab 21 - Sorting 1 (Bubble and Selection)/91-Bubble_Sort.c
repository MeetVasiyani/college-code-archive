/*91. Write a program to implement Bubble using Array. */

#include <stdio.h>

void main(){
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i=0; i<n; i++){
        printf("Enter element %d: ",i+1);
        scanf("%d", &arr[i]);
    }

    printf("Array before sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    int flag = 0;
    for(int i=0; i<n; i++){
        flag = 0;
        for(int j = i+1; j<n; j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                flag = 1;
            }
            if(flag == 0){
                break;
            }
        }
    }

    printf("Array after sorting: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}