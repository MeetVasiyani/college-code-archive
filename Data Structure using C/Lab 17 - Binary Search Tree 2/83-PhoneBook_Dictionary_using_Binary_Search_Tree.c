/*83. Write a program to implement phone book dictionary using Binary Search Tree 
which provides following operations: 
• Add new entry in phone book,  
• Remove entry from phone book,  
• Search phone number  
• List all entries in ascending order of name and 
• List all entries in descending order of name  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneEntry {
    char name[50];
    char phoneNumber[15];
    struct PhoneEntry *left;
    struct PhoneEntry *right;
};

struct PhoneEntry* createEntry(const char* name, const char* phoneNumber) {
    struct PhoneEntry* newEntry = (struct PhoneEntry*)malloc(sizeof(struct PhoneEntry));
    if (newEntry == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    strcpy(newEntry->name, name);
    strcpy(newEntry->phoneNumber, phoneNumber);
    newEntry->left = newEntry->right = NULL;
    return newEntry;
}

struct PhoneEntry* insertEntry(struct PhoneEntry* root, const char* name, const char* phoneNumber) {
    if (root == NULL) {
        return createEntry(name, phoneNumber);
    }

    int cmp = strcmp(name, root->name);
    if (cmp < 0) {
        root->left = insertEntry(root->left, name, phoneNumber);
    } else if (cmp > 0) {
        root->right = insertEntry(root->right, name, phoneNumber);
    } else {
        printf("Entry with name '%s' already exists. Ignoring insertion.\n", name);
    }
    return root;
}

struct PhoneEntry* minValueNode(struct PhoneEntry* node) {
    struct PhoneEntry* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct PhoneEntry* deleteEntry(struct PhoneEntry* root, const char* name) {
    if (root == NULL) {
        return root;
    }
    int cmp = strcmp(name, root->name);
    if (cmp < 0) {
        root->left = deleteEntry(root->left, name);
    } else if (cmp > 0) {
        root->right = deleteEntry(root->right, name);
    } else {
        if (root->left == NULL) {
            struct PhoneEntry* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct PhoneEntry* temp = root->left;
            free(root);
            return temp;
        }
        struct PhoneEntry* temp = minValueNode(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phoneNumber, temp->phoneNumber);
        root->right = deleteEntry(root->right, temp->name);
    }
    return root;
}

struct PhoneEntry* searchEntry(struct PhoneEntry* root, const char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }
    if (strcmp(name, root->name) < 0) {
        return searchEntry(root->left, name);
    }
    return searchEntry(root->right, name);
}

void inorderTraversal(struct PhoneEntry* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phoneNumber);
        inorderTraversal(root->right);
    }
}
void reverseInorderTraversal(struct PhoneEntry* root) {
    if (root != NULL) {
        reverseInorderTraversal(root->right);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phoneNumber);
        reverseInorderTraversal(root->left);
    }
}



void main(){
    struct PhoneEntry* root = NULL;
    int choice;
    char name[50];
    char phoneNumber[15];
    struct PhoneEntry* foundEntry;

    while(1) {
        printf("\nPhone Book Dictionary Menu:\n");
        printf("1. Add new entry\n");
        printf("2. Remove entry\n");
        printf("3. Search phone number\n");
        printf("4. List all entries in ascending order\n");
        printf("5. List all entries in descending order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
                root = insertEntry(root, name, phoneNumber);
                break;
            case 2:
                printf("Enter name to remove: ");
                scanf("%s", name);
                root = deleteEntry(root, name);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                foundEntry = searchEntry(root, name);
                if (foundEntry != NULL) {
                    printf("Phone Number: %s\n", foundEntry->phoneNumber);
                } else {
                    printf("Entry not found.\n");
                }
                break;
            case 4:
                printf("\nPhone Book Entries (Ascending Order):\n");
                inorderTraversal(root);
                break;
            case 5:
                printf("\nPhone Book Entries (Descending Order):\n");
                reverseInorderTraversal(root);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if (choice == 6) {
            break;
        }
    }
}

