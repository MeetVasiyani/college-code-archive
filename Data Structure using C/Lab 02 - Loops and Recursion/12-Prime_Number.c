/*12. WAP to check whether a number is prime or not. */
#include<stdio.h>
void main(){
    int num;
    printf("Enter a number : ");
    scanf("%d",&num);
    int flag=0;

    for(int i=2;i<num;i++){
        if(num%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("%d is a prime number",num);
    }
    else{
        printf("%d is not a prime number",num);
    }
}