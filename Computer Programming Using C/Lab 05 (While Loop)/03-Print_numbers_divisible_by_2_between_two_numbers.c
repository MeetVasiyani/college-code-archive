//Print numbers between two given numbers which is divisible by 2.
#include <stdio.h>
void main(){
    int i,n;
    printf("Enter first number :");
    scanf("%d",&n);
    printf("Enter second number:");
    scanf("%d",&i);
    while(n<i){
        if(n%2==0){
            printf("Numbers divisible by 2 are : %d\t",n);
        }
        n=n+1;
    }
}