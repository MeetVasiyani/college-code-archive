//Print odd numbers between 1 to 10 & 1 to n using while loop
/*#include <stdio.h>
void main(){
    int i=1;
    while(i<=10){
        printf("%d\t",i);
        i=i+2;
    }
}*/
 
#include <stdio.h>
void main(){
    int i=1,n;
    printf("Enter a number :");
    scanf("%d",&n);
    while(i<=n){
        printf("Odd number: %d\t",i);
        i=i+2;
    }
}

