//Read 3 numbers, multiply largest number from first two numbers to third one using switch.
#include <stdio.h>
void main(){
    int a,b,c;
    printf("Enter 1st integer :");
    scanf("%d",&a);
    printf("Enter 2nd integer :");
    scanf("%d",&b);
    printf("Enter 3rd integer :");
    scanf("%d",&c);
    a>b?printf("a is greater than b so a*c = %d",a*c):printf("b is greater than a so b*c = %d",b*c);
}