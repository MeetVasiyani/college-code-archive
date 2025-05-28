/*78. Write a program to check whether the given two trees are same or not.*/

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

bool isIdentical(struct Node* root1, struct Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL || root2 == NULL){
        return false;
    }
    else{
        return (root1->data == root2->data) 
        && isIdentical(root1->left, root2->left) 
        && isIdentical(root1->right, root2->right);
    }        
}

void main(){
    struct Node* root1 = createNode(3);
    root1->left = createNode(2);
    root1->right = createNode(4);
    root1->left->right = createNode(1);

    struct Node* root2 = createNode(3);
    root2->left = createNode(2);
    root2->right = createNode(4);
    root2->left->right = createNode(1);

    if(isIdentical(root1, root2)){
        printf("Trees are identical\n");
    }
    else{
        printf("Trees are not identical\n");
    }
    
}
