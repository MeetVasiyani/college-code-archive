/*Check whether given number is positive or negative.*/
#include<stdio.h>
void main(){
	int a;
	printf("Enter a number: ");
	scanf("%d",&a);
	if(a>0){
		printf("Number is positive");
	};
	if(a<0){
		printf("Number is negative");
	};
	if(a=0){
		printf("Number is zero");
	};
}
