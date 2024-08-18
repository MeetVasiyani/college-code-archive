/* Find factors of the given number*/
#include <stdio.h>
void main() {
    int number,i = 1;
    printf("Enter a number to calculate its factors: ");
    scanf("%d",&number);
    printf("The factors of %d are: ",number);
    while (i <= number) {
        if (number % i == 0) {
            printf("%d ", i);
        }
        i++;
    }
}
