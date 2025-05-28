/*14. WAP to find the sum of 1 + (1+2) + (1+2+3) + (1+2+3+4)+ …+(1+2+3+4+….+n).*/
#include<stdio.h>

void main(){
    int n,ans = 0,i = 1;

    printf("Enter the value of n: ");
    scanf("%d",&n);

    while(i <= n){
        int j = 1,sum = 0;
        while(j <= i){
            sum += j;
            j++;
        }
        ans += sum;
        i++;
    }
    printf("Sum of series is: %d",ans);
} 