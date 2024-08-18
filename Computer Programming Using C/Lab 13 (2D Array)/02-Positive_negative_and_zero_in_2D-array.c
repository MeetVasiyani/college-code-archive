/*Count number of positive, negative and zero elements from 3 X 3 matrix.*/
#include <stdio.h>

void main() {
    int matrix[3][3], i, j, positive = 0, negative = 0, zero = 0;

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (matrix[i][j] > 0) {
                positive++;
            } else if (matrix[i][j] < 0) {
                negative++;
            } else {
                zero++;
            }
        }
    }

    printf("Number of positive elements: %d\n", positive);
    printf("Number of negative elements: %d\n", negative);
    printf("Number of zero elements: %d\n", zero);

}
