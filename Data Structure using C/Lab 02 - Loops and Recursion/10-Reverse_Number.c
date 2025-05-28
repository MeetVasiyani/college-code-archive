/*10. WAP to reverse a number.*/
#include <stdio.h>

int reverse(int n){
    static int reset_rev = 0;
    if (n == 0)
        return reset_rev;
    else {
        reset_rev = reset_rev * 10 + n % 10;
        reverse(n / 10);
    }
}

void main(){
    int num, rev = 0, rem, original_num;
    printf("Enter a number : ");
    scanf("%d", &num);

    original_num = num;

    while(num != 0){
        rem = num % 10;
        rev = rev * 10 + rem;
        num = num / 10;
    }
    printf("Reversed number (iterative) is : %d\n", rev);

    printf("Reversed number (recursive) is : %d\n", reverse(original_num));
}