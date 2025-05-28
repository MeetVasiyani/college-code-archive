/*49. WAP to allocate and de-allocate memory for int, char and float variable at 
runtime.*/
#include<stdio.h>
#include<stdlib.h>

void main(){
    int *iptr;
    char *cptr;
    float *fptr;

    iptr = (int *)malloc(sizeof(int));
    cptr = (char *)malloc(sizeof(char));
    fptr = (float *)malloc(sizeof(float));

    if (iptr == NULL || cptr == NULL || fptr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    *cptr = 'A';
    *fptr = 3.14;

    printf("Value of integer: %d\n", *iptr);
    printf("Value of character: %c\n", *cptr);
    printf("Value of float: %f\n", *fptr);

    free(iptr);
    free(cptr);
    free(fptr);

    printf("Memory de-allocated successfully.\n");
    
}