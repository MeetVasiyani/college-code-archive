/*94. Write a program to implement Shell Sort using Array.*/

#include <stdio.h>

void main() {
    int n, i, j, gap, temp;

    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (gap = n / 2; gap >= 1; gap /= 2) {
        for (j = gap; j < n; j++) {
            for (i = j - gap; i >= 0 && a[i] > a[i + gap]; i -= gap) {
                temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}
