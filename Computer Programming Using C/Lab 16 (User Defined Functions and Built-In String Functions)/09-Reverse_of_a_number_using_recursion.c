/*Find reverse of any number using recursion.*/
#include <stdio.h>

int reverse(int num) {
    if (num < 10) {
        return num;
    } else {
        return (num % 10) * 10 + reverse(num / 10);
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reverse of %d is %d\n", num, reverse(num));

    return 0;
}