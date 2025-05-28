/*41. Write a program to convert infix notation to postfix notation using stack.*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000

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

char peep(int index){
    if(top - index + 1 == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top - index + 1];
}

int IPF(char c) {
    if (c == '+' || c == '-')      return 1;
    else if (c == '*' || c == '/') return 3;
    else if (c == '^')             return 6;
    else if (c == '(')             return 9;
    else if (c == ')')             return 0;
    else if (islower(c))           return 7;
    else                           return -1;
}

int SPF(char c) {
    if (c == '+' || c == '-')      return 2;
    else if (c == '*' || c == '/') return 4;
    else if (c == '^')             return 5;
    else if (c == '(')             return 0;
    else if (islower(c))           return 8;
    else                           return -1;
}

int RF(char c) {
    if (c=='+'||c=='-'||c=='*'||c=='/'||c=='^')
        return -1;
    return 1;
}

void main(){
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    int p = 0;
    int rank = 0;

    printf("Enter Your Infix Expression: ");
    scanf("%s", infix);

    int n = strlen(infix);

    push('(');
    infix[n++] = ')';
    infix[n]   = '\0';

    for (int i = 0; i < n; i++) {
        char next = infix[i];

        if (top < 0) {
            printf("Invalid\n");
            return 0;
        }

        while (SPF(peep(1)) > IPF(next)) {
            char t = pop();
            postfix[p++] = t;
            rank += RF(t);
            if (rank < 1) {
                printf("Invalid\n");
                return 0;
            }
        }

        if (SPF(peep(1)) != IPF(next)) {
            push(next);
        } else {
            pop();
        }
    }

    if (top != -1 || rank != 1) {
        printf("Invalid\n");
    } else {
        postfix[p] = '\0';
        printf("Valid\n");
        printf("Postfix Expression: %s\n", postfix);
    }
}