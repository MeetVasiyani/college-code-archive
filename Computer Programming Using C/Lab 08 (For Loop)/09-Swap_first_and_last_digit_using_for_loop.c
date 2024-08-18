/*Swap first and last digits of a number.*/
#include <stdio.h>
void main() {
    int num, temp, firstDigit, lastDigit, multiplier = 1;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;
    lastDigit = num % 10;
    while (temp >= 10) {
        temp /= 10;
        multiplier *= 10;
    }
    firstDigit = temp;
    num = num - (firstDigit * multiplier) + (lastDigit * multiplier) - lastDigit + firstDigit;

    printf("Number after swapping first and last digits: %d\n", num);
}