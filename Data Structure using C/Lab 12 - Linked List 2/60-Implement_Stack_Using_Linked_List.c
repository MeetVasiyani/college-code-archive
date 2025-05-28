/*60. Write a program to implement stack using singly linked list.*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void push(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void pop(){
    if (head == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    else {
        struct Node* temp = head;
        head = head->next;
        printf("Popped element: %d\n", temp->data);
        free(temp);
    }
}

void display(){
    if (head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct Node* curr = head;
    
    while (curr != NULL){
        printf("%d\n",curr->data);
        curr = curr->next;
    }    
}

void main(){
    int choice, data;
    while(1){
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d",&data);
                push(data);
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
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        if(choice == 4){
            printf("Exiting program...\n");
            break;
        }
    }
}