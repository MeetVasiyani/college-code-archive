/*70. Write a menu driven program to implement following operations on the circular 
linked list. 
• Insert a node at the front of the linked list. 
• Delete a node from specified position. 
• Insert a node at the end of the linked list. 
• Display all nodes. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFront(int value){
    struct Node* newNode = createNode(value);
    if(head == NULL){
        head = newNode;
        newNode->next = head;
        tail = head;
    }
    else{
        newNode->next = head;
        head = newNode;
        tail->next = head;
    }
}

void deleteAtSpecifiedPosition(int position){
    int count = 1;
    struct Node* temp = head;
    struct Node* prev = NULL;
    while(count < position){
        prev = temp;
        temp = temp->next;
        count++;
    }
    prev->next = temp->next;
    free(temp);
}

void insertAtEnd(int value){
    if(head == NULL){
        insertAtFront(value);
        return;
    }
    struct Node* newNode = createNode(value);
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

void display(){
    struct Node* temp = head;
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("Head\n");
}

void main(){
    int choice, value, position;
    while(1){
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at front\n");
        printf("2. Delete at specified position\n");
        printf("3. Insert at end\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtFront(value);
                display();
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtSpecifiedPosition(position);
                display();
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                display();
                break;
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
        }
        if(choice == 5){
            break;
        }
    }
}