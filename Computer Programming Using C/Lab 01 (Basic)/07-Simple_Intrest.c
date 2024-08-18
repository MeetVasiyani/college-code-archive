/*Print simple interest. (principal*roi*time period)/100 */
#include <stdio.h>
void main(){
	float p,r,t;
	printf("Enter the principle amount : ");
	scanf("%f",&p);
	printf("Enter the rate : ");
	scanf("%f",&r);
	printf("Enter the time : ");
	scanf("%f",&t);
	printf("The Simple Intrest = %f ",(p*r*t)/100);
	
}