/*Swap two numbers. (Using temporary variable and without using temporary variable)*/
#include<stdio.h>
void main(){
	int a,b,c;
	printf("Enter first number: ");
	scanf("%d",&a);
	printf("Enter second number: ");
	scanf("%d",&b);
	c=a;
	a=b;
	b=c;
	printf("First number :%d \n",a);
	printf("Second number :%d",b);
}
