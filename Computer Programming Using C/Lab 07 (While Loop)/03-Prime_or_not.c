/*Find whether the given number is prime or not.*/
#include <stdio.h>
void main() {
    int num, count=0,i = 2;

    printf("Enter a number: ");
    scanf("%d", &num);

    while (i < num) {
        if (num % i == 0) {
           count++; 
        }
        i++;
    }
    if(count!=0){
        printf("%d is not a prime number.\n", num);
    }
    else{
        printf("%d is a prime number.\n", num);
    }
}