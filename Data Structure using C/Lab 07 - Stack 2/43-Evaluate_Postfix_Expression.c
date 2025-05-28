/*43. Write a program for evaluation of postfix Expression using Stack. */
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

int evaluate(int a, char op, int b) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) {
                printf("Division by zero\n");
                return 0;
            }
            return a / b;
        case '^': {
            int result = 1;
            for (int i = 0; i < b; i++) result *= a;
            return result;
        }
        default:
            printf("Unknown operator: %c\n", op);
            return 0;
    }
}

void main(){
    char expr[MAX_SIZE];
    printf("Enter the postfix expression: ");
    scanf("%s", expr);

    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(c - '0');
        } else {
            int operand2 = pop();
            int operand1 = pop();
            int value = evaluate(operand1, c, operand2);
            push(value);
        }
    }

    if (top == 0) {
        int result = pop();
        printf("Result: %d\n", result);
    } else {
        printf("Invalid expression\n");
    }
}