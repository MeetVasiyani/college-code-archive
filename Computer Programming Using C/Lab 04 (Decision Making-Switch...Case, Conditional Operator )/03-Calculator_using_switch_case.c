/*Perform Addition, Subtraction, Multiplication and Division of 2 numbers as per user’s choice using switch. 
*/
#include <stdio.h>
void main(){
    float a,b;
    char o;
    printf("Enter 1st number: ");
    scanf("%f",&a);
    printf("Enter the operation :");
    scanf(" %c",&o);
    printf("Enter 2nd number: ");
    scanf("%f",&b);
    switch(o){
        case '+':
            printf("Answer = %f",a+b);
            break;
        case '-':
            printf("Answer = %f",a-b);
            break;
        case '*':
            printf("Answer = %f",a*b);
            break;
        case '/':
            printf("Answer = %f",a/b);
            break;
        
    }
}
