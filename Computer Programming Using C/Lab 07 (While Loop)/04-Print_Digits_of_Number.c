/*Print digits of given number.*/
#include <stdio.h>
int main() {
    int num,rev=0;
    printf("Enter a number: ");
    scanf("%d", &num);

    while (num != 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }

    while (rev != 0) {
        printf("%d\n", rev % 10);
        rev /= 10;
    }

}
