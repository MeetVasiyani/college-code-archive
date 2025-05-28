/*17. Write a program to calculate sum of numbers from m to n.*/

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

    int m,n,sum=0;
    printf("Enter starting index m : ");
    scanf("%d",&m);
    printf("Enter ending index n : ");
    scanf("%d",&n);
    for(int i=m-1;i<n;i++){
        sum+=arr[i];
    }

    printf("Sum of array elements from index %d to %d is : %d",m,n,sum);
}