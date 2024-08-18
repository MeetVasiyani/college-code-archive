/*Read a matrix and print diagonal elements and its sum.*/
#include <stdio.h>

void main() {
    int n, i, j, sum = 0;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Diagonal elements:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", matrix[i][i]);
        sum += matrix[i][i];
    }
    printf("\nSum of diagonal elements: %d\n", sum);
}
