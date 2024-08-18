/*Count number of elements divisible by 3 in array.*/
#include <stdio.h>

void main() {
    int n, i, count = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (arr[i] % 3 == 0) {
            count++;
        }
    }
    printf("Number of elements divisible by 3: %d\n", count);
}

