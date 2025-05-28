/*21. Read n numbers in an array then read two different numbers, replace 1st 
number with 2nd number in an array and print its index and final array.*/

#include<stdio.h>

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

    int num1,num2;
    printf("Enter  number to replace : ");
    scanf("%d",&num1);
    printf("Enter second number to replace with : ");
    scanf("%d",&num2);

    int index = -1;
    for(int i=0;i<len;i++){
        if(arr[i]==num1){
            arr[i] = num2;
            index = i;
            break;
        }
    }

    if(index != -1){
        printf("Number replaced at index %d\n",index+1);
        printf("Final Array Elements are : [ "); 
        for(int i = 0; i < len; i++){
            printf("%d ", arr[i]);
        }
        printf("]\n");
    } else {
        printf("Number %d not found in the array.\n", num1);
    }
}