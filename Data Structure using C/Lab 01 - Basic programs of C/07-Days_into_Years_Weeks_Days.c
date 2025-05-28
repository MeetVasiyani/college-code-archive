/*7. WAP to convert number of days into year, week & days [e.g. 375 days mean 1 year, 1 week and 3 days].*/

#include <stdio.h>

void main(){
    int days,years,weeks;
    printf("Enter number of days : ", &days);
    scanf("%d",&days);
    years = days/365;
    days = days - (years * 365);
    weeks = days/7;
    days = days - (weeks * 7);
    printf("%d year, %d week and %d days",years,weeks,days);
}