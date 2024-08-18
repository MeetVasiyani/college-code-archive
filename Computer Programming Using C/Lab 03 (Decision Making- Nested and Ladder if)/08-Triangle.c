/*Three sides of a triangle are entered through the keyboard, WAP to check whether the triangle is isosceles, 
equilateral, scalene or right angled triangle.*/
#include <stdio.h>
#include <math.h>

void main() {
    int side1, side2, side3;

    printf("Enter the three sides of the triangle: ");
    scanf("%d %d %d", &side1, &side2, &side3);

    
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1) {
        printf("Invalid triangle: Sum of two sides must be greater than the third side.\n");
        return 1;
    }

    if (side1 == side2 && side2 == side3) {
        printf("Equilateral triangle.\n");
    } else if (side1 == side2 || side1 == side3 || side2 == side3) {

        printf("Isosceles triangle.\n");
    } else {

        if (pow(side1, 2) == pow(side2, 2) + pow(side3, 2) ||
            pow(side2, 2) == pow(side1, 2) + pow(side3, 2) ||
            pow(side3, 2) == pow(side1, 2) + pow(side2, 2)) {
            printf("Right angled triangle.\n");
        } else {
            printf("Scalene triangle.\n");
        }
    }

}
