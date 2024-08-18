/*Find out sum of first and last digit of a given number.*/
#include <stdio.h>
void main() {
    int num, firstDigit, lastDigit;

    printf("Enter a number: ");
    scanf("%d", &num);

    lastDigit = num % 10;

    firstDigit = num;
    while(firstDigit >= 10) {
        firstDigit = firstDigit / 10;
    }

    int sum = firstDigit + lastDigit;

    printf("The sum of the first and last digit is: %d\n", sum);

}
