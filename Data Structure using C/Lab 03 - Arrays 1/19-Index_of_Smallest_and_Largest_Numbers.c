/*19. Write a program to find position of the smallest number & the largest number 
from given n numbers.*/

#include <stdio.h>

void main(){
    int len;
    printf("Enter length of the array : ");
    scanf("%d",&len);
    int arr[len];

    for(int i=0;i<len;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Array Elements are : [ "); 
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
    }
    printf("]\n");

    int smallest = arr[0];
    int largest = arr[0];
    int smallest_index = 0;
    int largest_index = 0;

    for(int i=1;i<len;i++){
        if(arr[i]<smallest){
            smallest = arr[i];
            smallest_index = i;
        }
        if(arr[i]>largest){
            largest = arr[i];
            largest_index = i;
        }
    }

    printf("Smallest Number : %d at index %d\n",smallest,smallest_index+1);
    printf("Largest Number : %d at index %d",largest,largest_index+1);
}
