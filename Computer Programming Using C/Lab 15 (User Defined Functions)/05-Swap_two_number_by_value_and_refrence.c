/*Swap two numbers using call by value and call by reference*/
#include <stdio.h>

int main() {
    int x = 10, y = 20;

    printf("Before swapping (call by value): x = %d, y = %d\n", x, y);
    swap_by_value(x, y);
    printf("After swapping (call by value): x = %d, y = %d\n", x, y);

    printf("\nBefore swapping (call by reference): x = %d, y = %d\n", x, y);
    swap_by_reference(&x, &y);
    printf("After swapping (call by reference): x = %d, y = %d\n", x, y);

    return 0;
}

void swap_by_value(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap_by_reference(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


