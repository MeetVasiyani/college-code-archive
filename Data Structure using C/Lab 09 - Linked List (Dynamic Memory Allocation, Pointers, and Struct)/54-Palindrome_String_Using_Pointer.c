/*54. WAP to check whether the string is Palindrome or not using Pointer. */

#include<stdio.h>
#include<string.h>

void main(){
    char str[20];
    
    printf("Enter your input string : ");
    scanf("%s",str);
    
    int len = strlen(str);
    char *ptr = str;
    
    for(int i=0;i<len/2;i++){
        if(*(ptr+i) != *(ptr+len-i-1)){
            printf("The string is not a palindrome.\n");
            return;
        }
    }
    
    printf("The string is a palindrome.\n");
    return;
}