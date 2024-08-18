/*Find HCF and LCM of two numbers.*/
#include <stdio.h>

void main() {
    int num1, num2,i,hcf, lcm;
    printf("Enter 1st number: ");
    scanf("%d", &num1);
    printf("Enter 2nd number: ");
    scanf("%d", &num2);
    i=1;
    while (i<=num1 && i<=num2) {
        if(num1%i==0 && num2%i==0){
            hcf=i;}
        i++;
    }
    lcm = (num1*num2) / hcf;

    printf("The HCF of %d and %d is %d.\n", num1, num2, hcf);
    printf("The LCM of %d and %d is %d.\n", num1, num2, lcm);

}

