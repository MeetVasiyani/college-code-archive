/*67. WAP to perform given operation in the linked list. There exist a Linked List. Add 
a node that contains the GCD of that two nodes between every pair adjacent 
node of Linked List. */

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

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a%b);
}

void insertGCDNodes(){
    if(head == NULL || head->next == NULL){
        printf("Linked List is empty or has only one node, no GCD nodes to insert.\n");
        return;
    }
    struct Node* curr = head;
    while(curr->next != NULL){
        int g = gcd(curr->data, curr->next->data);
        struct Node* newNode = createNode(g);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = curr->next->next;
    }
}

void main(){
    //menu driven
    int choice;
    while(1){
        printf("\n1. Insert at end\n");
        printf("2. Delete last\n");
        printf("3. Insert GCD nodes\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                int value;
                scanf("%d", &value);
                insertAtEnd(value);
                display();
                break;
            case 2:
                deleteLast();
                display();
                break;
            case 3:
                insertGCDNodes();
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
            printf("Exiting program...\n");
            break;
        }
    }
}
