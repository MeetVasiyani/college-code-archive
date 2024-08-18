/*Check whether the given number is Armstrong or not.*/
#include <stdio.h>
#include <math.h>
void main(){
    int n,i,k,count=0,ams=0,j;
    printf("Enter a number: ");
    scanf("%d",&n);
    i=n;
    k=n;
    while(n!=0){
        if(n%10!=0){
            count++;
            }
        n=n/10;
    }
    while(i!=0){
        j=i%10;
        ams+=pow(j,count);
        i=i/10;
    }
    if(ams=k){
        printf("It is an armstrong number");
    }
    else{
        printf("It is not an armstrong number");
    }
}


