#include <stdio.h>

int sumUptoN(int n){
    int sum = 0;

    if(n < 0){
        return sum;
    }
    return sumUptoN(n-1) + n;
}
void main(){
    int n, sum;
    printf("Enter a number : ");
    scanf("%d",&n);

    // for(int i = 1; i <= n; i++){
    //     sum += i;
    // }

    //sum = (n*(n+1))/2;

    sum = sumUptoN(n);

    printf("Sum of first %d natural numbers is : %d",n,sum);

}
