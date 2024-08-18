/*Perform Addition of two matrices. */
#include <stdio.h>
void main() {
    int ROWS = 3, COLS = 3;
    int matrix1[ROWS][COLS], matrix2[ROWS][COLS], resultMatrix[ROWS][COLS];

    printf("Enter elements of matrix 1 (%d x %d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of matrix 2 (%d x %d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Result of matrix addition:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            resultMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

}
