/*Read five person height and weight and count the number of person having height greater than 170 and 
weight less than 50.*/
#include <stdio.h>

void main() {
    int i, height, weight, count = 0;

    for (i = 1; i <= 5; i++) {
        printf("Enter the height and weight of person %d: ", i);
        scanf("%d %d", &height, &weight);

        if (height > 170 && weight < 50) {
            count++;
        }
    }

    printf("The number of persons having height greater than 170 and weight less than 50 is: %d\n", count);

}
