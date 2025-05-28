/*6. WAP to convert seconds into hours, minutes & seconds and print in HH:MM:SS 
[e.g. 10000 seconds mean 2:46:40 (2 Hours, 46 Minutes, 40 Seconds)].*/

#include <stdio.h>

void main(){
    int sec,hours,minutes;
    printf("Enter time in seconds : ");
    scanf("%d",&sec);
    hours = sec / 3600;
    sec = sec - (hours * 3600);
    minutes = sec / 60;
    sec = sec - (minutes * 60);
    printf("Time Given - %d : %d : %d",hours,minutes,sec);
}