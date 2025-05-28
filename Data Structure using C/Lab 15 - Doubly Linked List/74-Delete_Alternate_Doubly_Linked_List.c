/*74. WAP to delete alternate nodes of a doubly linked list.*/

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

void insertAtEnd(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtEnd(){
    if(head == NULL){
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    if(temp->prev == NULL){
        head = NULL;
    }
    else{
        temp->prev->next = NULL;
    }
    free(temp);
}

void deleteAlternateNodes(){
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL){
        struct Node* nextNode = temp->next;
        if(nextNode != NULL){
            temp->next = nextNode->next;
            if(nextNode->next != NULL){
                nextNode->next->prev = temp;
            }
            free(nextNode);
        }
        temp = temp->next;
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
    int choice, data;
    while(1){
        printf("\n1. Insert at end\n");
        printf("2. Delete at end\n");
        printf("3. Delete alternate nodes\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                display();
                break;
            case 2:
                deleteAtEnd();
                display();
                break;
            case 3:
                deleteAlternateNodes();
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