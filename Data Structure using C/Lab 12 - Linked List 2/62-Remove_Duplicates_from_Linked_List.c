/*62. WAP to remove duplicate elements from a singly linked list. */

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

void removeDuplicates(){
    struct Node* curr = head;

    while(curr != NULL){
        struct Node* prev = curr;
        struct Node* runner = curr->next;
        while(runner != NULL){
            if(runner->data == curr->data){
                prev->next = runner->next;
                free(runner);
                runner = prev->next;
            }
            else{
                prev = runner;
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

void main(){
    //menu driven
    int choice, value;
    while(1){
        printf("\n1. Insert at End\n");
        printf("2. Display\n");
        printf("3. Delete Last\n");
        printf("4. Remove Duplicates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                display();
                break;
            case 2:
                display();
                break;
            case 3:
                deleteLast();
                display();
                break;
            case 4:
                removeDuplicates();
                printf("Duplicates removed.\n");
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if(choice == 5){
            break;
        }
    }
}
