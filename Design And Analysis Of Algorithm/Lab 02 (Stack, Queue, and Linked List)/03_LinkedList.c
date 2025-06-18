#include <stdio.h>
#include <stdlib.h>


struct Node{
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

void insertFirst(int data){
    struct Node* newNode = createNode(data);
    if(head == NULL){
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void deleteFirst(int data){
    if(head == NULL){
        printf("Linked List is empty !");
        return;
    }else{
        struct Node* curr = head;
        head = head->next;
        curr->next = NULL;
        free(curr);
    }
}

void insertLast(int data){
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
}

void deleteLast(int data){
    if(head == NULL){
        printf("Linked List is empty !");
        return;
    }else{
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
    if(head == NULL){
        printf("Linked List is empty !");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
}

void main(){
    int choice, value;
    while(1){
        printf("\nLinked List Operations Menu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Delete from beginning\n");
        printf("3. Insert at end\n");
        printf("4. Delete from end\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertFirst(value);
                display();
                break;
            case 2:
                deleteFirst(value);
                display();
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertLast(value);
                display();
                break;
            case 4:
                deleteLast(value);
                display();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        if(choice == 6){
            break;
        }
    }
}
