/*Multiply and divide a number by 2 without using multiplication/division operator.*/
#include<stdio.h>
void main(){
    int a,b,c;
    printf("Enter a Number : ");
    scanf("%d",&a);
    b=a>>1;
    c=a<<1;
    printf("Multiplication by 2 of a is: %d \n",c);
    printf("Divide by 2 of a is: %d",b);
}