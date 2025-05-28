/*58. Write a program to count the number of nodes in a singly circular linked list.*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(int data) {
    struct Node *newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}

void display(){
    if (head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct Node* curr = head;
    
    while (curr->next != NULL){
        printf("%d -> ",curr->data);
        curr = curr->next;
    } 
}

int countNodes() {
    int count = 0;
    if (head == NULL) {
        return count;
    }
    struct Node *current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

void main(){
    insertNode(10);
    insertNode(20);
    insertNode(30);
    insertNode(40);
    insertNode(50);
    display();
    printf("Number of nodes in the circular linked list: %d\n", countNodes());
}