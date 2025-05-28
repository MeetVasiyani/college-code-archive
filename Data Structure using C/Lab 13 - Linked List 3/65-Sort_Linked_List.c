/*65. Write a program to sort elements of a linked list. */

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

void sortList(){
    if(head == NULL || head->next == NULL){
        return;
    }

    struct Node* i;
    struct Node* j;

    for (i = head; i != NULL; i = i->next){
        for (j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
        
    }
}

void main(){
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Sort List\n");
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
                sortList();
                printf("List sorted successfully.\n");
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