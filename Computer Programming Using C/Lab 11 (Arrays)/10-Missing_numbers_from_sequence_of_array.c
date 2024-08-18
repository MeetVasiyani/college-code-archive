/* Find missing numbers of sequence using array.(in a sequence 1,2,4,5,7,8,10, Missing numbers are 3,6,9). */

#include <stdio.h>

void main() {
    int n, i, j, a[100], flag = 0;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("Missing Numbers: ");
    for (i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] > 1) {
            for (j = a[i] + 1; j < a[i + 1]; j++) {
                printf("%d ", j);
                flag = 1;
            }
        }
    }

    if (flag == 0) {
        printf("No missing numbers found.\n");
    }

}


