/*Allocate dynamic memory for structure variable*/
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[50];
    int age;
};

void main() {
    struct Person *person_ptr;

    person_ptr = (struct Person *)malloc(sizeof(struct Person));

    if (person_ptr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter name: ");
    scanf("%s", person_ptr->name);

    printf("Enter age: ");
    scanf("%d", &person_ptr->age);

    printf("Name: %s\n", person_ptr->name);
    printf("Age: %d\n", person_ptr->age);

    free(person_ptr);

}
