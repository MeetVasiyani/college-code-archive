/*56. Write a program to implement a node structure for singly linked list. Read the 
data in a node, print the node. */

#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void main(){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    

    printf("Enter data for the new node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    printf("Value stored in newNode : %d", newNode->data);
    printf("Pointer of newNode : %d", newNode->next);

    free(newNode);
    newNode = NULL;
}