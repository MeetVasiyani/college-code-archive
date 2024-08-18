/*Print Pascal triangle.
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1*/
#include <stdio.h>

void main() {
    int rows, i, j;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (i = 1; i <= rows; i++) {
        int num = 1;
        for (j = 1; j <= i; j++) {
            printf("%d ", num);
            num = num * (i - j) / j;
        }

        printf("\n");
    }

}
