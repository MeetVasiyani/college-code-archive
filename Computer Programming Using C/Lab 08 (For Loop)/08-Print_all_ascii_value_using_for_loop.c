/*Print all ASCII character with their values.*/
#include <stdio.h>

void main() {
    printf("ASCII Characters with their values:\n");
    for (int i = 0; i <= 255; i++) {
        printf("ASCII value of %c = %d\n", i, i);
    }
}
