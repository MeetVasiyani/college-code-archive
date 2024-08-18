/*Find the second largest number among three user input numbers.*/
#include <stdio.h>

void main() {
    int num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int largest = num1;
    if (num2 > largest) {
        largest = num2;
    }
    if (num3 > largest) {
        largest = num3;
    }

    int secondLargest = num1;
    if (num2 > secondLargest && num2 != largest) {
        secondLargest = num2;
    }
    if (num3 > secondLargest && num3 != largest) {
        secondLargest = num3;
    }

    printf("The second largest number is: %d\n", secondLargest);

}
