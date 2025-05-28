/*80. Given a binary tree, determine if it is height-balanced (A height-balanced binary 
tree is a binary tree in which the depth of the two subtrees of every node never 
differs by more than one). */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int height(struct Node* node){
    if (node == NULL){
        return 0;
    }

    return 1 + fmax(height(node->left), height(node->right));
    
}

bool isBalanced(struct Node* node){
    if (node == NULL){
        return true;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if (abs(leftHeight - rightHeight) > 1){
        return false;
    }

    return isBalanced(node->left) && isBalanced(node->right);
}

void main(){
    struct Node* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);
    if(isBalanced(root)){
        printf("The tree is height-balanced.\n");
    }
    else{
        printf("The tree is not height-balanced.\n");
    }
}