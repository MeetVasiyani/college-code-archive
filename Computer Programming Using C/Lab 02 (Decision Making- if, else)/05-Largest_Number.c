/*Find out largest number from given three numbers. */
#include<stdio.h>
void main(){
	int a,b,c;
	printf("Enter first number: ");
	scanf("%d",&a);
	printf("Enter second number: ");
	scanf("%d",&b);
	printf("Enter third number: ");
	scanf("%d",&c);
	if(a>b && a>c){
		printf("%d is the largest number",a);
	};
	if(b>a && b>c){
		printf("%d is the largest number",b);
	};
	if(c>b && c>a){
		printf("%d is the largest number",c);
	};
	
}
