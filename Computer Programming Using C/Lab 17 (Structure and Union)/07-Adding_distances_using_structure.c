/*Add two distances in feet and inches using structure.*/
#include <stdio.h>

struct Distance {
    int feet;
    float inch;
};

void main() {
    struct Distance dist1;
    printf("Enter 1st distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist1.feet);
    printf("Enter inch: ");
    scanf("%f", &dist1.inch);

    struct Distance dist2;
    printf("\nEnter 2nd distance\n");
    printf("Enter feet: ");
    scanf("%d", &dist2.feet);
    printf("Enter inch: ");
    scanf("%f", &dist2.inch);

    struct Distance sum;
    sum.feet = dist1.feet + dist2.feet;
    sum.inch = dist1.inch + dist2.inch;

    while (sum.inch >= 12) {
        sum.inch -= 12;
        ++sum.feet;
    }

    printf("\nSum of distances = %d'%.1f\"", sum.feet, sum.inch);
}
