/*42. Write a program to convert infix notation to prefix notation using stack. */

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
    if (c == '+' || c == '-')      return 2;
    else if (c == '*' || c == '/') return 4;
    else if (c == '^')             return 5;
    else if (c == '(')             return 9;
    else if (c == ')')             return 0;
    else if (islower(c))           return 7;
    else                           return -1;
}

int SPF(char c) {
    if (c == '+' || c == '-')      return 1;
    else if (c == '*' || c == '/') return 3;
    else if (c == '^')             return 6;
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
    char input[MAX_SIZE];
    char infix[MAX_SIZE];
    char tempPrefix[MAX_SIZE];
    int tp = 0;
    int rank = 0;

    printf("Enter Your Infix Expression: ");
    scanf("%s", input);
    
    int len = strlen(input);
    
    for (int i = len - 1; i >= 0; i--) {
        char c = input[i];
        if (c == '(')      infix[len - 1 - i] = ')';
        else if (c == ')') infix[len - 1 - i] = '(';
        else                infix[len - 1 - i] = c;
    }

    infix[len] = ')';
    infix[len + 1] = '\0';
    push('(');

    for (int i = 0; infix[i] != '\0'; i++) {
        char next = infix[i];

        if (top < 0) {
            printf("Invalid\n");
            return 0;
        }

        while (SPF(peep(1)) > IPF(next)) {
            char op = pop();
            tempPrefix[tp++] = op;
            rank += RF(op);
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
        return 0;
    }

    tempPrefix[tp] = '\0';

    char prefix[MAX_SIZE];
    for (int i = 0; i < tp; i++) {
        prefix[i] = tempPrefix[tp - 1 - i];
    }
    prefix[tp] = '\0';

    printf("Valid\n");
    printf("Prefix Expression: %s\n", prefix);

}