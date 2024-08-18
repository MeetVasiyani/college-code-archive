/*Count number of even or odd number from an array of n numbers.*/
#include <stdio.h>

void main() {
    int n, i, count_even = 0, count_odd = 0;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count_even++;
        } else {
            count_odd++;
        }
    }

    printf("Number of even numbers: %d\n", count_even);
    printf("Number of odd numbers: %d\n", count_odd);

}
