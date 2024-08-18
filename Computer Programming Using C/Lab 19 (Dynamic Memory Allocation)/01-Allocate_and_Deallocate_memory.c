/*Allocate and de-allocate memory for int, char and float variable at run time.*/
#include <stdio.h>
#include <stdlib.h>

void main() {
    int *int_ptr;
    char *char_ptr;
    float *float_ptr;

    int_ptr = (int *)malloc(sizeof(int));
    char_ptr = (char *)malloc(sizeof(char));
    float_ptr = (float *)malloc(sizeof(float));

    if (int_ptr == NULL || char_ptr == NULL || float_ptr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    free(int_ptr);
    free(char_ptr);
    free(float_ptr);

}
