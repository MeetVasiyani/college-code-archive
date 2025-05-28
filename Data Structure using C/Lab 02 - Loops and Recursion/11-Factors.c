/*11. WAP to find factors of a given number. */
#include <stdio.h>

void main(){
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    printf("Factors of the given number are : ");
    for(int i = 1; i <= num; i++){
        if (num % i == 0){
            printf("%d ",i);
        }
    }
}