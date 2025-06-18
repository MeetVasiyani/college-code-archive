#include <stdio.h>

int fact(int n){
    if(n <= 1){
        return 1;
    }
    return n * fact(n-1);
}

void main(){

    int n, res = 1;
    printf("Enter a number : ");
    scanf("%d",&n);

    // for(int i = 1; i <= n; i++){
    //     res *= i;
    // }

    res = fact(n);

    printf("Factorial of %d is %d",n,res);
}

