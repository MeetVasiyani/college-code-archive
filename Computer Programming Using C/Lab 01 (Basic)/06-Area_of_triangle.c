/*Print area of triangle. ((height*base)/2)*/
#include <stdio.h>
void main(){
	float h,b;
	printf("Enter height of the triangle : ");
	scanf("%f",&h);
	printf("Enter base of the triangle : ");
	scanf("%f",&b);
	printf("Area of the triangle = %f",(h*b)/2);
}
