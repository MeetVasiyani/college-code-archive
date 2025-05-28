/*82. WAP to find the smallest and largest elements in the Binary Search Tree.*/

#include <stdio.h>
#include <stdlib.h>
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

struct Node* insertNode(struct Node* root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void main(){
    struct Node* root = NULL;
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    root = insertNode(root, 75);
    root = insertNode(root, 12);
    root = insertNode(root, 37);
    root = insertNode(root, 62);
    root = insertNode(root, 87);
    root = insertNode(root, 6);
    root = insertNode(root, 18);
    root = insertNode(root, 31);
    root = insertNode(root, 43);
    root = insertNode(root, 56);
    root = insertNode(root, 68);
    root = insertNode(root, 81);
    root = insertNode(root, 93);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    struct Node* smallest = root;
    while(smallest->left != NULL){
        smallest = smallest->left;
    }
    printf("Smallest element in the BST: %d\n", smallest->data);

    struct Node* largest = root;
    while(largest->right != NULL){
        largest = largest->right;
    }
    printf("Largest element in the BST: %d\n", largest->data);

}
