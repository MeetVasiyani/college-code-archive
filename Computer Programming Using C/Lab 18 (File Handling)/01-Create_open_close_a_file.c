/*Create, open and close a file. */
#include <stdio.h>

int main() {
    FILE *fp;
    fp = fopen("abc.txt", "w");
    
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(fp, "Hello, this is content written to abc.txt!\n");
    
    fclose(fp);
    
    return 0;
}