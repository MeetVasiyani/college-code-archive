/*90. Write a program to implement a Binary Search using Array. (Iterative & 
recursive). */

#include <stdio.h>

void main(){
    int arr[100], n, key, left, right, mid, i;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    
    printf("Enter the elements of the array (sorted): \n");
    for(i = 0; i < n; i++){
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    
    left = 0;
    right = n - 1;
    int found = 0;

    while(left <= right){
        mid = (left + right) / 2;
        
        if(arr[mid] == key){
            found = 1;
            break;
        }
        else if(arr[mid] < key){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }

    if(found){
        printf("Element found at position %d\n", mid + 1);
    } else {
        printf("Element not found\n");
    }
}

//Recursive

/*
int binarySearch(int start,int end,int arr[]){
    int mid;
    if(start > end)
        return -1;
    else{
        mid = (start + end) / 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            return binarySearch(mid + 1, end, arr);
        else
            return binarySearch(start, mid - 1, arr);
    }
}
*/