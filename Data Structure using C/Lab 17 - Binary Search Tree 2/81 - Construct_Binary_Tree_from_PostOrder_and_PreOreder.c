/*81. Write a program to construct a binary tree from given Postorder and Preorder 
traversal sequence.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) exit(EXIT_FAILURE);
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

