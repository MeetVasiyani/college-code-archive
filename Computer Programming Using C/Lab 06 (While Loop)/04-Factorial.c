/*Find factorial of the given number.*/
#include <stdio.h>
void main(){
    int number, i = 1, factorial = 1;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d",&number);
    while (i <= number) {
        factorial *= i;
        i++;
    }
    printf("The factorial of %d is %d.\n", number, factorial);
}
