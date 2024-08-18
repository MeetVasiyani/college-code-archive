//Print sum of series 1 + 4 + 9 + 16 + 25 + 36 + …n.
#include <stdio.h>
void main(){
    int i=1,n,sum=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    while(i<=n){
        sum=sum+i*i;
        i=i+1;
    }
    printf("Total of all numbers: %d",sum);
}
