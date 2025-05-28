/*68. Write a program to swap two consecutive nodes in the linked list. Don’t change 
the values of nodes, implement by changing the link of the nodes. 
• Input: 1 → 2 → 3 → 4 → 5 → 6 → 7 → 8 
• Output: 2 → 1 → 4 → 3 → 6 → 5 → 8 → 7 */

#include<stdio.h>
#include<stdlib.h>

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

void swapTwoConsecutiveNodes(){
    if (head == NULL || head->next == NULL) {
        printf("Linked List is empty or has only one node\n");
        return;
    }
    struct Node* curr = head;
    struct Node* prev = NULL;
    head = head->next;

    while (curr != NULL && curr->next != NULL){   
        struct Node* temp = curr->next;
        curr->next = temp->next;
        temp->next = curr;
        if (prev != NULL){
            prev->next = temp;
        }
        prev = curr;
        curr = curr->next;
    }
    
}

void main(){
    int choice, value;

    while(1){
        printf("1. Insert at end\n");
        printf("2. Delete last\n");
        printf("3. Display\n");
        printf("4. Swap two consecutive nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&value);
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
                swapTwoConsecutiveNodes();
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