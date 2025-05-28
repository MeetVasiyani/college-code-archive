/*87. In an array of 20 elements, arrange 15 different values, which are generated 
randomly between 1,00,000 to 9,99,999. Use hash function to generate key and 
linear probing to avoid collision. H(x) = (x mod 18) + 2. Write a program to input 
and display the final values of array. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20
#define NUM_VALUES 15

int hash(int value) {
    return (value % 18) + 2;
}

void main() {
    int arr[SIZE] = {0};
    int values[NUM_VALUES];
    int i, key;

    srand(time(NULL));

    for (i = 0; i < NUM_VALUES; i++) {
        int newValue;
        int isUnique;
        do {
            newValue = rand() % 900000 + 100000;
            isUnique = 1;
            for (int j = 0; j < i; j++) {
                if (values[j] == newValue) {
                    isUnique = 0;
                    break;
                }
            }
        } while (!isUnique);
        values[i] = newValue;
    }

    for (i = 0; i < NUM_VALUES; i++) {
        key = hash(values[i]);
        while (arr[key] != 0) { 
            key = (key + 1) % SIZE;
        }
        arr[key] = values[i];
    }

    printf("Final array:\n");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}
