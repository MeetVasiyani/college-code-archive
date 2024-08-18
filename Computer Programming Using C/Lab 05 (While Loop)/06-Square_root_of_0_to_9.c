//Print number and its square root for 0 to 9.
#include <stdio.h>
#include <math.h>
void main(){
    int i=0;
    while(i<10){
        printf("square root of %d is %f\n",i,pow(i,(1/2.0))); //sqrt(i)
        i++;
    }
}