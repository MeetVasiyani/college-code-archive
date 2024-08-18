/*Find the sum and average of different numbers which are accepted by user as many as user wants*/
#include <stdio.h>

void main() {
    int i = 0, n, sum = 0, number;
    float average;

    printf("Enter how many numbers you want to add: ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    while (i < n) {
        scanf("%d", &number);
        sum += number;
        i++;
    }

    average = (float)sum / n;

    printf("The sum of the %d numbers is %d.\n", n, sum);
    printf("The average of the %d numbers is %.2f.\n", n, average);

}
