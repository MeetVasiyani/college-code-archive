/*Read and store the roll no and marks of 20 students using 2D array.*/
#include <stdio.h>

void main() {
    int roll_no[20], marks[20];
    int i;

    printf("Enter roll numbers of 20 students:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &roll_no[i]);
    }

    printf("Enter marks of 20 students:\n");
    for (i = 0; i < 20; i++) {
        scanf("%d", &marks[i]);
    }

    printf("\nRoll No\tMarks\n");
    for (i = 0; i < 20; i++) {
        printf("%d\t%d\n", roll_no[i], marks[i]);
    }

}
