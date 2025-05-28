/*64. Write a program to reverse a linked list. */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
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
    printf("NULL\n");
}

void reverse(){
    if(head == NULL || head->next == NULL){
        return;
    }
    struct Node* curr = head;
    struct Node* prev = NULL;
    while (curr != NULL){
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;    
}

void main(){
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Reverse List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                display();
                break;
            case 2:
                printf("Original List: ");
                display();
                break;
            case 3:
                reverse();
                printf("List reversed successfully.\n");
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
        if (choice == 4) {
            break;
        }
    }
}
