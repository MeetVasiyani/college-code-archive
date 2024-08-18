//Print 1 to 10 & Print 1 to n using while loop
/*#include <stdio.h>
void main(){
    int i=1;
    while (i<=10){
        printf("Numbers 1 to 10: %d\t",i);
        i=i+1;
    }
}*/
#include <stdio.h>
void main(){
    int n,i=1;
    printf("Enter a number : ");
    scanf("%d",&n);
    while(i<=n){
        printf("All numbers: %d\t",i);
        i=i+1;}
}