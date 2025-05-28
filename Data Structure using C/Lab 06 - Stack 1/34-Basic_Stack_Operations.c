/*34. Write a menu driven program to implement following operations on the Stack 
using an Array 
• PUSH, POP, DISPLAY 
• PEEP, CHANGE */

#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void display(){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: \n");
    for(int i = top; i >= 0; i--){
        printf("%d\n", stack[i]);
    }
}

int peep(int index){
    if(top == -1){
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top-index+1];
}

void change(int index,int value){
    if(top == -1){
        printf("Stack is empty\n");
        return;
    }
    stack[top-index+1] = value;
}

void main(){
    while (1)
    {
        printf("\nStack Operations Menu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. PEEP\n");
        printf("5. CHANGE\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            int value;
            scanf("%d", &value);
            push(value);
            display();
            break;
        case 2:
            pop();
            display();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Enter index to peep: ");
            int index;
            scanf("%d", &index);
            printf("Element at index %d is %d", index, peep(index));
            break;
        case 5:
            printf("Enter index of change: ");
            int index_c;
            scanf("%d", &index_c);
            printf("Enter new value: ");
            int value_c;
            scanf("%d", &value_c);
            change(index_c, value_c);
            display();
            break;
        case 6:
            return;
        default:
            printf("Invalid choice\n");
            break;
        }
        
    }
    
}