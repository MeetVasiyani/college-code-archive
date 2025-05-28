/*20. Write a program to find whether the array contains a duplicate number or not.*/
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

    int flag = 0;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            if(arr[i]==arr[j]){
                flag = 1;
                break;
            }
        }
    }

    if (flag == 1)
    {
        printf("The given array contains duplicates.");
    }
    else{
        printf("The given array does not contain duplicates.");
    }
}