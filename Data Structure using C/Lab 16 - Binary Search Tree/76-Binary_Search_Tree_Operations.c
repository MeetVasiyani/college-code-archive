/*76. Write a menu driven program to implement Binary Search Tree (BST) & perform 
following operations:  
• Insert a node 
• Delete a node 
• Search a node*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insertNode(int value){
    if(root == NULL){
        struct Node* newNode = createNode(value);
        root = newNode;
    }
    else{
        struct Node* temp = createNode(value);
        struct Node* parent = NULL;
        struct Node* curr = root;
        while(curr != NULL){
            parent = curr;
            if(value < curr->data){
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
            if(curr == NULL){
                if(value < parent->data){
                    parent->left = temp;
                }
                else{
                    parent->right = temp;
                }
            }
        }
    }

}

void deleteNode(int value){
    struct Node* parent = NULL;
    struct Node* curr = root;

    while(curr != NULL && curr->data != value){
        parent = curr;
        if(value < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    if(curr == NULL){
        printf("Node with value %d not found.\n", value);
        return;
    }
    if(curr->left == NULL && curr->right == NULL){
        if(curr == root){
            root = NULL;
        }
        else{
            if(parent->left == curr){
                parent->left = NULL;
            }
            else{
                parent->right = NULL;
            }
            free(curr);
        }
    }
    else if(curr->left == NULL || curr->right == NULL){
        struct Node* child;
        if(curr->left != NULL){
            child = curr->left;
        }
        else{
            child = curr->right;
        }
        if(curr == root){
            root = child;
        }
        else{
            if(parent->left == curr){
                parent->left = child;
            }
            else{
                parent->right = child;
            }
            free(curr);
        }
    }
    else{
        struct Node* successorParent = curr;
        struct Node* successor = curr->right;
        while(successor->left != NULL){
            successorParent = successor;
            successor = successor->left;
        }
        if(curr == root){
            root = successor;
            successor->left = curr->left;
        }
        else{
            if(parent->left == curr){
                parent->left = successor;
            }
            else{
                parent->right = successor;
            }
            successor->left = curr->left;
            successor->right = curr->right;
        }
        free(curr);
    }
}

void searchNode(int value){
    struct Node* curr = root;
    while(curr != NULL && curr->data != value){
        if(value < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }    
    }
    if (curr == NULL){
        printf("Node with value %d not found.\n", value);
    }
    else{
        printf("Node with value %d found.\n", value);
    }
}

void main(){
    int choice, value;
    while(1){
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchNode(value);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if(choice == 4){
            break;
        }
    }
}