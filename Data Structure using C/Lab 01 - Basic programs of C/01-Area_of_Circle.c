/*1. WAP to calculate area of a Circle (A = πr2). */

#include <stdio.h>

void main(){
    float radius, area;
    printf("Enter radius of circle : ");
    scanf("%f",&radius);
    area = 3.14159 * radius * radius;
    printf("Area of Circle with given radius is : %f.",area);
}