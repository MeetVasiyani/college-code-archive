/*59. WAP to check whether 2 singly linked lists are same or not.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* list1head = NULL;
struct Node* list2head = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(int value, struct Node* head){
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

void display(struct Node* head){
    if (head == NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct Node* curr = head;
    
    while (curr != NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

bool areListsSame(struct Node* list1, struct Node* list2) {
    while (list1 != NULL && list2 != NULL) {
        if (list1->data != list2->data) {
            return false;
        }
        list1 = list1->next;
        list2 = list2->next;
    }
    return (list1 == NULL && list2 == NULL);
}

void main(){
    insertAtEnd(10, list1head);
    insertAtEnd(20, list1head);
    insertAtEnd(30, list1head);

    insertAtEnd(10, list2head);
    insertAtEnd(20, list2head);
    insertAtEnd(30, list2head);

    printf("List 1: ");
    display(list1head);
    printf("List 2: ");
    display(list2head);

    if (areListsSame(list1head, list2head)) {
        printf("The two linked lists are the same.\n");
    } else {
        printf("The two linked lists are not the same.\n");
    }    
}