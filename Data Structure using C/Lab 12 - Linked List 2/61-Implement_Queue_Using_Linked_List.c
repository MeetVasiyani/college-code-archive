/*61. Write a program to implement queue using singly linked list. */

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

void enqueue(int value){
    struct Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void dequeue(){
    if(head == NULL){
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else{
        struct Node* temp = head;
        head = head->next;
        temp->next = NULL;
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
        printf("%d ",curr->data);
        curr = curr->next;
    }    
}

void main(){
    //implement menu like queue
    int choice, data;
    while(1){
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d",&data);
                enqueue(data);
                display();
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
        if(choice == 4){
            printf("Exiting program...\n");
            break;
        }
    
    }
}