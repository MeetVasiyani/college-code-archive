/*Enter basic salary of an employee and calculate Gross salary according to given conditions: 
- Basic Salary >= 10000 : HRA = 20% of basic, DA = 80% of basic 
- Basic Salary >= 20000 : HRA = 25% of basic, DA = 90% of basic 
- Basic Salary >= 30000 : HRA = 30% of basic, DA = 95% of basic */
#include <stdio.h>
void main(){
    float BS,HRA,DA;
    printf("Enter the Basic Salary = ");
    scanf("%f",&BS);
    if(BS<10000){
        HRA=BS*0.15;
        DA=BS*0.07;
        printf("Basic Salary = %f",BS);
        printf("\nHRA = %f",HRA);
        printf("\nDA = %f",DA);
        printf("\nGross Salary = %f",BS+HRA+DA);
    }
    else if(BS>=10000 && BS<20000){
        HRA=BS*0.20;
        DA=BS*0.80;
        printf("Basic Salary = %f",BS);
        printf("\nHRA = %f",HRA);
        printf("\nDA = %f",DA);
        printf("\nGross Salary = %f",BS+HRA+DA);
    }
    else if(BS>=20000 && BS<30000){
        HRA=BS*0.25;
        DA=BS*0.90;
        printf("Basic Salary = %f",BS);
        printf("\nHRA = %f",HRA);
        printf("\nDA = %f",DA);
        printf("\nGross Salary = %f",BS+HRA+DA);
    }
    else if(BS>=30000){
        HRA=BS*0.30;
        DA=BS*0.95;
        printf("Basic Salary = %f",BS);
        printf("\nHRA = %f",HRA);
        printf("\nDA = %f",DA);
        printf("\nGross Salary = %f",BS+HRA+DA);
    }
}