/*Check whether number is even number or odd number using conditional operator. */
#include <stdio.h>
void main(){
    int a;
    printf("Enter an integer :");
    scanf("%d",&a);
    a%2==0?printf("%d is an even integer",a):printf("%d is an odd integer",a);
}