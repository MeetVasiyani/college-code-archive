/*5. WAP to check for the leap year.*/
#include <stdio.h>

void main(){
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    if(year % 400 == 0){
        printf("Given year %d is a leap year",year);
    }
    else if(year % 100 == 0){
        printf("Given year %d is not a leap year",year);
    }
    else if(year % 4 == 0){
        printf("Given year %d is a leap year",year);
    }
    else{
        printf("Given year %d is not a leap year",year);
    }

    /*
    Compound Condition :
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("Given year %d is a leap year", year);
    } 
    else {
        printf("Given year %d is not a leap year", year);
    }
    */
}