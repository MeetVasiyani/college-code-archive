/*22. WAP to print Pascal triangle.*/
#include <stdio.h>

int factorial(int n){
    if(n == 0|| n == 1){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}

void main(){
    int n;
    printf("Enter the number of rows:");
    scanf("%d",&n);
    
    for (int i = 0; i < n; i++){ 

        for (int j = 0; j < n-i-1; j++){
            printf(" ");
        }

        for(int k = 0; k <= i; k++){
            int term = factorial(i)/(factorial(k) * factorial(i-k));
            printf("%d ",term);
        }
        printf("\n");
    }
    
}