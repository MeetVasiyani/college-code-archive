/*73. Write a menu driven program to implement following operations on the doubly 
linked list. 
• Insert a node at the front of the linked list. 
• Delete a node from specified position. 
• Insert a node at the end of the linked list. (Home Work) 
• Display all nodes. (Home Work)*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node *head = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtFront(int data){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void deleteAtSpecifiedPosition(int position){
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    int count = 1;

    if(position == 1) {
        head = head->next;
        if(head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    while(temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL) {
        printf("Position out of bounds.\n");
        return;
    }

    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp);
}

void insertAtEnd(int data){
    struct Node *newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        struct Node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

void display(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("List: ");
    while(temp != NULL){
        printf("%d <=> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main(){
    int choice, data, position;

    while(1){
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert at front\n");
        printf("2. Delete at specified position\n");
        printf("3. Insert at end\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(data);
                display();
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtSpecifiedPosition(position);
                display();
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
        if(choice == 5){
            break;
        }
    }
}