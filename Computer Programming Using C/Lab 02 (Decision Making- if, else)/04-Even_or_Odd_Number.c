/*Check whether the given number is odd or even.*/
#include<stdio.h>
void main(){
	int a;
	printf("Enter a number: ");
	scanf("%d",&a);
	if(a%2==0){
		printf("Number is even");
	};
	if(a%2!=0){
		printf("Number is odd");
	};
	if(a=0){
		printf("Number is zero");
	};
}
