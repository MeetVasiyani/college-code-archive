/*Find whether the given number is prime or not using flag.*/
#include <stdio.h>
void main() {
    int num, i = 2, flag = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    while(i <= num/2) {
        if(num % i == 0) {
            flag = 1;
        }
        i++;
    }
    if(flag == 0)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
}

