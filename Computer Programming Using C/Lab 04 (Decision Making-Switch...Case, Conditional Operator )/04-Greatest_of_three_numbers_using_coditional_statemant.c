/*Find out largest number from given 3 numbers using conditional operator.*/
#include <stdio.h>
void main(){
    int a,b,c;
    printf("Enter 1st integer :");
    scanf("%d",&a);
    printf("Enter 2nd integer :");
    scanf("%d",&b);
    printf("Enter 3rd integer :");
    scanf("%d",&c);
    a>b?(a>c?printf("%d is greatest",a):printf("%d is greatest",c)):(b>c?printf("%d is greatest",b):printf("%d is greatest",c));
}