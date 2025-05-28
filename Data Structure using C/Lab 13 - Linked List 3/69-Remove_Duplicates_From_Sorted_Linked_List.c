/*69. Write a program to remove the duplicates nodes from given sorted Linked List. 
• Input: 1 → 1 → 6 → 13 → 13 → 13 → 27 → 27 
• Output: 1 → 6 → 13 → 27 */

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

void removeDuplicates(){
    if(head == NULL || head->next == NULL){
        return;
    }
    struct Node* curr = head;
    struct Node* prev = NULL;
    while(curr != NULL){
        if(curr->next != NULL && curr->data == curr->next->data){
            struct Node* temp = curr->next;
            curr->next = temp->next;
            free(temp);
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}

void main(){
    //menu driven
    int choice, value;
    while (1){
        printf("1. Insert at end\n");
        printf("2. Delete last\n");
        printf("3. Display\n");
        printf("4. Remove duplicates\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                display();
                break;
            case 2:
                deleteLast();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                removeDuplicates();
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        if(choice == 5){
            break;
        }
    }
}