/*4. WAP to find the largest among the given three numbers by user.*/
#include <stdio.h>

void main(){
    int num1,num2,num3;

    printf("Enter first number : ");
    scanf("%d",&num1);
    printf("Enter second number : ");
    scanf("%d",&num2);
    printf("Enter third number : ");
    scanf("%d",&num3);

    if(num1 > num2){
        if(num1 > num3){
            printf("Largest number is %d", num1);
        }
        else{
            printf("Largest number is %d", num3);
        }
    }
    else{
        if(num2 > num3){
            printf("Largest number is %d", num2);
        }
        else{
            printf("Largest number is %d", num3);
        }
    }
    /*
    Using Ternary :
        largest = (num1 > num2) ? (num1 > num3) ? num1 : num3 : (num2 > num3) ? num2 : num3;
        printf("Largest number is %d", largest);
    */
}