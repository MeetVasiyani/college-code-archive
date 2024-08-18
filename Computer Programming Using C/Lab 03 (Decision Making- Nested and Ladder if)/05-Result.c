/* Read marks of five subjects. Calculate percentage and print class accordingly. Fail below 35, Pass Class
between 36 to 45, Second Class between 46 to 60, First Class between 61 to 70, Distinction if more than 
70*/
#include <stdio.h>
void main(){
    float E,P,C,M,B,a;
    printf("Enter the marks of English :");
    scanf("%f",&E);
    printf("Enter the marks of Maths :");
    scanf("%f",&M);
    printf("Enter the marks of Physics :");
    scanf("%f",&P);
    printf("Enter the marks of Chemistry :");
    scanf("%f",&C);
    printf("Enter the marks of Biology :");
    scanf("%f",&B);
    a=(E+P+C+M+B)/5;

    if(a<35.0){
        printf("The student has Failed %f percent",a);
    }
    else if(36.0<=a && a<=45.0){
        printf("The student has recieved Pass Class with %f percent",a);
        }
    else if(46.0<=a && a<=60.0){
        printf("The student has recieved Second Class with %f percent",a);
        }
    else if(61.0<=a && a<=70.0){
        printf("The student has recieved First Class with %f percent",a);
        }
    else if(70.0<a){
        printf("The student has recieved Distinction with %f percent",a);
        }
}