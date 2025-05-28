/*35. How stack can be used to recognize strings aca, bcb, abcba, abbcbba? Write a 
program to solve the above problem. */

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char value){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    int len = strlen(str);

    int flag = -1;
    int is_recognized = 1;
    for(int i = 0; i < len; i++){
        if(str[i] != 'c'){
            push(str[i]);
        }
        else{
            flag = i;
            break;
        }
    }

    for(int i = flag+1; i < len; i++){
        if(str[i] != pop()){
            is_recognized = 0;
            break;
        }
    }


    printf("String is %srecognized\n", is_recognized && top == -1 ? "" : "not ");
}