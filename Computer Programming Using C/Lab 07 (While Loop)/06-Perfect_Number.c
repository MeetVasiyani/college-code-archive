/*Check whether the given number is perfect or not.*/
#include <stdio.h>
void main() {
    int num, i = 1, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    while(i < num) {
        if(num % i == 0)
            sum = sum + i;
        i++; 
    }

    if(sum == num)
        printf("%d is a perfect number.\n", num);
    else
        printf("%d is not a perfect number.\n", num);

}
