#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int power;
    struct Node* next;
};

struct Node* createNode(int coeff, int power) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->power = power;
    new_node->next = NULL;
    return new_node;
}

void insert(struct Node** head, int coeff, int power) {
    struct Node* new_node = createNode(coeff, power);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
}

void printList(struct Node* head) {
    printf("Linked List:\n");
    while (head != NULL) {
        printf(" %dx^%d", head->coeff, head->power);
        head = head->next;
    }
    printf("\n");
}

void addPolynomials(struct Node* head1, struct Node* head2) {
    if (head1 == NULL && head2 == NULL)
        return;

    if (head1 != NULL && head2 != NULL && head1->power == head2->power) {
        printf(" %dx^%d", head1->coeff + head2->coeff, head1->power);
        addPolynomials(head1->next, head2->next);
    } else if (head2 == NULL || (head1 != NULL && head1->power > head2->power)) {
        printf(" %dx^%d", head1->coeff, head1->power);
        addPolynomials(head1->next, head2);
    } else {
        printf(" %dx^%d", head2->coeff, head2->power);
        addPolynomials(head1, head2->next);
    }
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insert(&head1, 5, 2);
    insert(&head1, 4, 1);

    insert(&head2, 6, 2);
    insert(&head2, 4, 1);

    printList(head1);
    printList(head2);

    printf("Addition:\n");
    addPolynomials(head1, head2);
    printf("\n");

    return 0;
}
