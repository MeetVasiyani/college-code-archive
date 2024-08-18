/*Calculate 𝑥^𝑦 without using power function.*/
#include <stdio.h>
void main() {
    int x, y,z,result=1;
    printf("Enter the value of x: ");
    scanf("%d",&x);
    printf("Enter the value of y: ");
    scanf("%d",&y);
    z=y;
    while (z != 0) {
        result *= x;
        --z;
    }
    printf("%d raise to the power %d = %d\n", x, y, result);
}
