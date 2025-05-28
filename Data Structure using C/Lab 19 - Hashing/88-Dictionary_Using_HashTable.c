/*88. Implement a Dictionary (key, value) pair using Hash-table.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 20

typedef struct {
    char key[50];
    char value[50];
} KeyValuePair;

KeyValuePair* hashTable[TABLE_SIZE];

void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashFunction(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}
void insert(char* key, char* value) {
    int index = hashFunction(key);
    KeyValuePair* newPair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    strcpy(newPair->key, key);
    strcpy(newPair->value, value);

    while (hashTable[index] != NULL) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = newPair;
}

KeyValuePair* search(char* key) {
    int index = hashFunction(key);
    while (hashTable[index] != NULL) {
        if (strcmp(hashTable[index]->key, key) == 0) {
            return hashTable[index];
        }
        index = (index + 1) % TABLE_SIZE;
    }
    return NULL;
}

void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Key: %s, Value: %s\n", hashTable[i]->key, hashTable[i]->value);
        }
    }
}

void main(){
    int choice;
    char key[50], value[50];
    initializeHashTable();
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%s", value);
                insert(key, value);
                break;
            case 2:
                printf("Enter key to search: ");
                scanf("%s", key);
                KeyValuePair* result = search(key);
                if (result != NULL) {
                    printf("Value: %s\n", result->value);
                } else {
                    printf("Key not found.\n");
                }
                break;
            case 3:
                printf("Dictionary:\n");
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        if (choice == 4) {
            break;
        }
    }
}
