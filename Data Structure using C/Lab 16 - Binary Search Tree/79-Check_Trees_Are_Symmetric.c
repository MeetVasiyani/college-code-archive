/*79. Write a program to check whether the given tree is symmetric or not. */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool isMirror(struct Node* leftSub, struct Node* rightSub){
    if(leftSub == NULL && rightSub == NULL){
        return true;
    }
    else if(leftSub == NULL || rightSub == NULL || leftSub->data != rightSub->data){
        return false;
    }
    else{
        return isMirror(leftSub->left, rightSub->right) 
        && isMirror(leftSub->right, rightSub->left);
    }        
}

bool isSymmetric(struct Node* root){
    if(root == NULL){
        return true;
    }
    return isMirror(root->left, root->right);
}

void main(){
    struct Node* root = createNode(8);
    root->left = createNode(5);
    root->right = createNode(5);
    root->left->left = createNode(3);
    root->left->right = createNode(6);
    root->right->left = createNode(6);
    root->right->right = createNode(3);

    if(isSymmetric(root)){
        printf("The tree is symmetric.\n");
    }
    else{
        printf("The tree is not symmetric.\n");
    }    
}
