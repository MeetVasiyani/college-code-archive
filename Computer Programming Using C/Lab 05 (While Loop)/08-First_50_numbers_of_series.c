/*Print first 50 numbers in series 1, 4, 7, 10… .*/
#include <stdio.h>
void main(){
    int i=1,n=1;
    while(i<=50){
        printf("%d\t",n);
        n=n+3;
        i=i+1;
    }
}

