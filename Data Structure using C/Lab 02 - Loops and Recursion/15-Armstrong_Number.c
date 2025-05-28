/*15. WAP to print Armstrong number from 1 to 1000.*/

#include<stdio.h>
#include<math.h>

int isArmstrong(int n){
    int count;
    count = (n == 0) ? 1 : log10(n) + 1;
    int temp = count, sum = 0, duplicate = n;
    while(count != 0){
        sum += pow(duplicate%10,temp);
        duplicate /= 10;
        count--;
    }
    return sum == n;
}

void main(){
    printf("Armstrong numbers from 1 to 1000 are : ");
    for(int i=1;i<=1000;i++){
        if (isArmstrong(i))
        {
            printf("%d ",i);
        }
    }
}