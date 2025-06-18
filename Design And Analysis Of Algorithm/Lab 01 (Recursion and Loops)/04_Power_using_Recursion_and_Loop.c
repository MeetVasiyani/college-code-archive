#include <stdio.h>

int power(int n,int pow){
    if(pow == 1){
        return n;
    }
    return n*power(n,pow-1);
}

void main(){
    int n,res = 1,pow;
    printf("Enter a number : ");
    scanf("%d",&n);

    printf("Enter the power : ");
    scanf("%d",&pow);

    // for(int i=1;i<=pow;i++){
    //     res = res*n;
    // }


    res = power(n,pow);
    printf("Result : %d",res);
}