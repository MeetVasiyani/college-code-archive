/*Print value and address of a variable.*/
#include <stdio.h>
void main() {
    int num = 42;
    int *ptr = &num;
    printf("Value of num: %d\n", *ptr);
    printf("Address of num: %d\n", ptr);
}