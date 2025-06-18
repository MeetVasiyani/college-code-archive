#include <stdio.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];
int top = -1;

void push(int n){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow");
        return;
    }
    stack[++top] = n;
}

int pop(){
    if(top == -1){
        printf("Stack Underflow");
        return -1;
    }
    return stack[top--];
}

void display(){
    if (top == -1){
        printf("Stack is empty");
        return;
    }
    for(int i = top; i >= 0; i--){
        printf("%d\n",stack[i]);
    }
    return;
}

int peep(int index){
    if(top == -1){
        printf("Stack is empty !");
        return -1;
    }
    return stack[top-index+1];
}

void main(){
    while (1)
    {
        printf("\nStack Operations Menu:\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. DISPLAY\n");
        printf("4. PEEP\n");
        printf("5. Exit\n");
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
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
        if (choice == 5)
        {
            break;
        }
        
    }
}