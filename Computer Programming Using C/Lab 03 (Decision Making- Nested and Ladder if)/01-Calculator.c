/*Perform Addition, Subtraction, Multiplication and Division of 2 numbers as per user’s choice. */
#include<stdio.h>
void main(){
	char c;
	float a,b;
	printf("Enter the first number : ");
	scanf("%f",&a);
	printf("Enter the operation : ");
	scanf(" %c",&c);
	printf("Enter the second number : ");
	scanf("%f",&b);
	if (c=='+'){
		printf("Answer = %f",a+b);
	}
	else if (c=='-'){
		printf("Answer = %f",a-b);
	}
	else if (c=='*'){
		printf("Answer = %f",a*b);
	}
	else if (c=='/'){
		printf("Answer = %f",a/b);
	}
}
