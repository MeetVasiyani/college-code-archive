#include <stdio.h>

int countDigits(int n){
    if(n == 0){
        return 0;
    }
    return 1 + countDigits(n/10);
}

void main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    //Iterative
    // int res = 0;
    // while(n != 0){
    //     n = n/10;
    //     res++;
    // }

    int res = countDigits(n);
    printf("Number of digits : %d",res);
}