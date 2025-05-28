/*63. Write a program to copy a linked list.*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* copyList(struct Node* head) {
    struct Node* newHead = NULL;
    struct Node* tail = NULL;
    struct Node* current = head;

    while (current != NULL) {
        struct Node* newNode = createNode(current->data);
        if (newHead == NULL) {
            newHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        current = current->next;
    }
    return newHead;
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void main() {
    //menu driven
    struct Node* head = NULL;
    struct Node* copiedList = NULL;
    int choice, data;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Copy List\n");
        printf("4. Display Copied List\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                displayList(head);
                break;
            case 2:
                printf("Original List: ");
                displayList(head);
                break;
            case 3:
                copiedList = copyList(head);
                printf("List copied successfully.\n");
                break;
            case 4:
                printf("Copied List: ");
                displayList(copiedList);
                break;
            case 5:
                freeList(head);
                freeList(copiedList);
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
        if (choice == 5) {
            break;
        }
    }
}
