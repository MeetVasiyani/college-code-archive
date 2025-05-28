/*71. WAP to split a circular linked list into two halves. */

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

void insertAtEnd(int value){
    if(head == NULL){
        head = createNode(value);
        tail = head;
        head->next = head;
        return;
    }
    struct Node* newNode = createNode(value);
    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
}

void deleteAtEnd(){
    if(head == NULL){
        printf("Circular Linked List is empty\n");
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        tail = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    temp->next = head; 
    free(tail);
    tail = temp;
}

void display(struct Node* head){
    struct Node* temp = head;
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("Head\n");
}

void splitListIntoTwoHalves() {
    if (head == NULL) {
            printf("The given Circular Linked List is Empty");
            return;
        }
    if (head->next == head) {
        printf("The given Circular Linked List is too small to split");
        return;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    struct Node* secondHead = slow->next;
    slow->next = head;
    tail->next = secondHead;
    tail = head;
    head = secondHead;
}

void main(){
    //menu driven
    int choice, value;
    while(1){
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at end\n");
        printf("2. Delete at end\n");
        printf("3. Split list into two halves\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                display(head);
                break;
            case 2:
                deleteAtEnd();
                display(head);
                break;
            case 3:
                splitListIntoTwoHalves();
                printf("List split into two halves.\n");
                printf("First half: ");
                display(tail);
                printf("Second half: ");
                display(head);
                break;
            case 4:
                display(head);
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

