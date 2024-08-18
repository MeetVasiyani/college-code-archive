//Get 10 numbers from user print count of odd, even numbers.
#include <stdio.h>
void main(){
    int i=1,n,e=0,o=0;
    while(i<=10){
        printf("Enter a number: ");
        scanf("%d",&n);
        if(n%2==0){
            e=e+1;
        }
        else{
            o=o+1;
        }
        i++;
    }
    printf("No. of even numbers : %d\n",e);
    printf("No. of odd numbers : %d",o);
}