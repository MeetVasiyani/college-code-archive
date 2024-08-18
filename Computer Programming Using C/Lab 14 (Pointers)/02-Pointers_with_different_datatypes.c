/*Demonstrate int, float, double and char pointer. */
#include <stdio.h>
void main() {
    int intVar = 42;
    float floatVar = 3.14;
    double doubleVar = 2.71828;
    char charVar = 'A';

    int *intPtr = &intVar;
    float *floatPtr = &floatVar;
    double *doublePtr = &doubleVar;
    char *charPtr = &charVar;

    printf("Value of intVar: %d, Address of intVar: %d\n", *intPtr,intPtr);
    printf("Value of floatVar: %f,Address of floatVar: %d\n", *floatPtr,floatPtr);
    printf("Value of doubleVar: %lf,Address of doubleVar: %d\n",*doublePtr,doublePtr);
    printf("Value of charVar: %c,Address of charVar: %d\n", *charPtr,charPtr);

}