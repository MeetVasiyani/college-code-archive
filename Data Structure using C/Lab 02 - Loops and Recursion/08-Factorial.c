/*8. WAP to find factorial of a number. (Using loop & recursion)*/
#include <stdio.h>

int factorial(int n){
    if(n == 0|| n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

void main(){
    int num,ans;
    printf("Enter a number : ");
    scanf("%d",&num);
    //Using loop
    ans = 1;
    for(int i = 1; i <= num; i++){
        ans = ans * i;
    }
    printf("Factorial of the given number %d is : %d",num,ans);

    //Using recursion
    printf("\nFactorial of the given number %d is : %d",num,factorial(num));
}

