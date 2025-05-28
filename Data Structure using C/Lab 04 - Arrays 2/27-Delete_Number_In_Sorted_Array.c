/*27. Write a program to delete a number from an array that is already sorted in an 
ascending order.*/

#include <stdio.h>

void main(){
    int n;
    printf("Enter length of original array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of original array in ascending order:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int num;
    printf("Enter number to be deleted : ");
    scanf("%d", &num);

    int foundIndex = -1;
    for(int i = 0; i < n; i++){
        if (arr[i] == num){
            foundIndex = i;
            break;
        }        
    }
    if(foundIndex != -1){
        for(int i = foundIndex; i < n - 1; i++){
            arr[i] = arr[i + 1];
        }
        n--;
    }
    else{
        printf("Number not found in array.\n");
    }
    printf("Updated array:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}