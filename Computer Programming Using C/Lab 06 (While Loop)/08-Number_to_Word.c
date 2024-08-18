/* Convert given number in words. (i.e. n=3456  output: Three Four Five Six)*/
#include <stdio.h>
int main() {
    int n, rev = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    while(n != 0) {
        digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    printf("The given number is: ");
    while(rev != 0) {
        switch(rev % 10) {
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
        }
        rev /= 10;
    }
}