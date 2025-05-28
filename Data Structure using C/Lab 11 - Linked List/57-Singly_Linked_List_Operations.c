/*57. Write a menu driven program to implement following operations on the singly 
linked list.  
• Insert a node at the front of the linked list. 
• Display all nodes. 
• Delete a first node of the linked list. 
• Insert a node at the end of the linked list. 
• Delete a last node of the linked list. 
• Delete a node from specified position. */
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

void insertAtFront(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void display(){
    if (head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct Node* curr = head;
    
    while (curr != NULL){
        printf("%d -> ",curr->data);
        curr = curr->next;
    }    
}

void deleteFirst(){
    struct Node* temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
}

void insertAtEnd(int value){
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

void deleteLast(){
    if(head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    else{
        struct Node* curr = head;
        struct Node* prev = NULL;
        while(curr->next != NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        free(curr);
    }
}

void deleteFromSpecifiedPosition(int position){
    if(head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    if (position <= 0) {
        printf("Invalid position. Position must be positive.\n");
        return;
    }
    else{
        if(position == 1){
            deleteFirst();
            return;
        }

        int count = 1;
        struct Node* curr = head;
        struct Node* prev = NULL;
        while(count != position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        if (curr == NULL) {
            printf("Position %d is out of bounds. Cannot delete.\n", position);
            return;
        }

        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
    }
}

void main(){
    int choice, data, position;
    while(1){
        printf("\nSingly Linked List Operations:\n");
        printf("1. Insert at front\n");
        printf("2. Display\n");
        printf("3. Delete first\n");
        printf("4. Insert at end\n");
        printf("5. Delete last\n");
        printf("6. Delete from specified position\n");
        printf("7. Exit\n");
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
                display();
                break;
            case 3:
                deleteFirst();
                display();
                break;
            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                display();
                break;
            case 5:
                deleteLast();
                display();
                break;
            case 6:
                printf("Enter position to delete from: ");
                scanf("%d", &position);
                deleteFromSpecifiedPosition(position);
                display();
                break;
            case 7:
                break;
            default:
                printf("Invalid choice\n");
        }
        if(choice == 7){
            break;
        }
    }
}