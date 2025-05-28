/*66. WAP to swap Kth node from beginning with Kth node from end in a singly linked 
list.*/

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

int countNodes() {
    int count = 0;
    if (head == NULL) {
        return count;
    }
    struct Node *current = head;
    do {
        count++;
        current = current->next;
    } while (current != NULL);
    return count;
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

void swapKthNode(int k){
    if(head == NULL || head->next == NULL){
        printf("Linked List is empty or has only one node\n");
        return;
    }

    int n = countNodes();

    if (k <= 0 || k > n) {
        printf("Invalid value of k: %d. k must be between 1 and %d.\n", k, n);
        return;
    }

    if(k == (n-k+1)){
        printf("Kth node from beginning and end are the same. No swap needed.\n");
        return;
    }

    if(k > (n - k + 1)){
        k = n - k + 1;
    }

    struct Node *node1 = NULL, *prev1 = NULL;
    struct Node *node2 = NULL, *prev2 = NULL;

    struct Node* current = head;
    struct Node* prev = NULL;

    for (int i = 1; i < k; i++) {
        prev = current;
        current = current->next;
    }
    node1 = current;
    prev1 = prev;

    current = head;
    prev = NULL;
    for (int i = 1; i < (n - k + 1); i++) {
        prev = current;
        current = current->next;
    }
    prev2 = prev;
    node2 = current;

    if (prev1 == NULL) {
        head = node2;
    } else {
        prev1->next = node2;
    }

    if (prev2 == NULL) {
        head = node1;
    } else {
        prev2->next = node1;
    }

    struct Node* temp_next = node1->next;
    node1->next = node2->next;
    node2->next = temp_next;

}

void main(){
    int choice, data, k;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at End\n");
        printf("2. Display List\n");
        printf("3. Swap Kth Node\n");
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
                printf("Enter the value of k: ");
                scanf("%d", &k);
                swapKthNode(k);
                printf("Kth nodes swapped successfully.\n");
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