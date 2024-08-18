/*Input an integer number and check the last digit of number is even or odd*/
#include <stdio.h>
void main(){
    int a;
    printf("Enter an integer : ");
    scanf("%d",&a);
    if (a&1){
        printf("Last digit is odd");
    }
    else {
        printf("Last digit is even");
    }
}