/*2. WAP to find whether a number is odd or even.*/

#include <stdio.h>

void main(){
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    if (num % 2 == 0){
        printf("Given number %d is Even.",num);
    }
    else{
        printf("Given number %d is Odd.",num);
    }
}