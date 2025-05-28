/*18. Write a program to calculate average of first n numbers. */

#include<stdio.h>

void main(){

    int len,sum = 0,n;
    float avg;

    printf("Enter length of the array : ");
    scanf("%d",&len);
    int arr[len];

    for(int i=0;i<len;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Average of first how many elements to find ? : ");
    scanf("%d",&n);

    printf("Array Elements are : [ "); 
    for(int i = 0; i < len; i++){
        printf("%d ", arr[i]);
        if(i < n){
            sum += arr[i];
        }        
    }
    printf("]\n");

    avg = sum/n;
    printf("Average of first %d elements is : %f",n,avg);
}