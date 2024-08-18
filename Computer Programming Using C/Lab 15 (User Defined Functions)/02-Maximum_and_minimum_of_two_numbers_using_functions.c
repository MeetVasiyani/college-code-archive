/*Find maximum and minimum between two numbers using function.*/
#include <stdio.h>
int main() {
    int num1, num2;
    int max, min;

    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    find_max_min(num1, num2, &max, &min);

    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}

void find_max_min(int a, int b, int *max, int *min) {
    if (a > b) {
        *max = a;
        *min = b;
    } 
    else {
        *max = b;
        *min = a;
    }
}

