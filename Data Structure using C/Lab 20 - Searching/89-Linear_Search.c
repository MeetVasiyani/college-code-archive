/*89. Write a program to implement a Linear Search using Array. */

#include<stdio.h>

void main(){
    int a[100],n,key,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }

    printf("Enter the element to be searched: \n");
    scanf("%d",&key);

    int flag = 0;

    for(i=0;i<n;i++){
        if(a[i]==key){
            flag=1;
            break;
        }
    }

    if(flag==1){
        printf("Element found at position %d",i+1);
    }
    else{
        printf("Element not found");
    }
}