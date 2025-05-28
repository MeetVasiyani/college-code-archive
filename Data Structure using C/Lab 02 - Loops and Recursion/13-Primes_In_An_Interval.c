/*13. WAP to print prime numbers between given interval. */
#include<stdio.h>
int isPrime(int n){
    for(int i = 2; i < n; i++){
        if (n % i == 0)
        {
            return 0;
        }
        
    }
    return 1;
}

void main(){

    int a,b;

    printf("Enter first number : ");
    scanf("%d", &a);
    printf("Enter second number : ");
    scanf("%d", &b);

    printf("Prime numbers between %d and %d are : ", a, b);
    
    for(int i = a; i <= b; i++){
        if(isPrime(i)){
            printf("%d ", i);
        }
    }
}